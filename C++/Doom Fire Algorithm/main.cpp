#include <iostream>
#include <cstdlib>
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

int WINDOW_HEIGHT = 720 / 4;
int WINDOW_WIDTH = 1280 / 4;

int* firePixelsArray = new int[(WINDOW_WIDTH) * (WINDOW_HEIGHT)];
int numberOfPixels = (WINDOW_WIDTH) * (WINDOW_HEIGHT); 

int fireColoursPalette[37][3] = {{7, 7, 7}, {31, 7, 7}, {47, 15, 7}, {71, 15, 7}, {87, 23, 7}, {103, 31, 7}, {119, 31, 7}, {143, 39, 7}, {159, 47, 7}, {175, 63, 7}, {191, 71, 7}, {199, 71, 7}, {223, 79, 7}, {223, 87, 7}, {223, 87, 7}, {215, 95, 7}, {215, 95, 7}, {215, 103, 15}, {207, 111, 15}, {207, 119, 15}, {207, 127, 15}, {207, 135, 23}, {199, 135, 23}, {199, 143, 23}, {199, 151, 31}, {191, 159, 31}, {191, 159, 31}, {191, 167, 39}, {191, 167, 39}, {191, 175, 47}, {183, 175, 47}, {183, 183, 47}, {183, 183, 55}, {207, 207, 111}, {223, 223, 159}, {239, 239, 199}, {255, 255, 255}};

class FireSim : public olc::PixelGameEngine {
public:
    FireSim() {
        sAppName = "Doom Fire Simulator";   
    }

    bool OnUserCreate() override {
        for (int i = 0; i < numberOfPixels; i++) {
            firePixelsArray[i] = 36;
        }
        return true;
    };

    bool OnUserUpdate(float fElapsedTime) override {
        m_timeAccumilator += fElapsedTime;
        if (m_timeAccumilator >= 0.033) {
            m_timeAccumilator = 0.0f;
            #pragma omp parallel for schedule(dynamic)
            for (int i = 0; i < numberOfPixels; i++) {
                UpdateFireIntensity(i);
            }
        }
        Render();

        if (GetMouse(0).bHeld) {
            Vec2<int> m = {GetMouseX(), GetMouseY()};
            auto fillCircle = [&](int x, int y, int radius, int val) {
                // Taken from wikipedia
                int x0 = 0;
                int y0 = radius;
                int d = 3 - 2 * radius;
                if (!radius) return;

                auto drawline = [&](int sx, int ex, int ny) {
                    for (int i = sx; i <= ex; i++)
                        firePixelsArray[ny * WINDOW_WIDTH + i] = val;
                };

                while (y0 >= x0) {
                    // Modified to draw scan-lines instead of edges
                    drawline(x - x0, x + x0, y - y0);
                    drawline(x - y0, x + y0, y - x0);
                    drawline(x - x0, x + x0, y + y0);
                    drawline(x - y0, x + y0, y + x0);
                    if (d < 0) d += 4 * x0++ + 6;
                    else d += 4 * (x0++ - y0--) + 10;
                }
            };
            fillCircle(m.x, m.y, 4, 36);
        }

        return true;
    }

    void UpdateFireIntensity(int pixel) {
        int pixelBelowIndex = pixel + WINDOW_WIDTH;
        if (pixelBelowIndex < numberOfPixels) {
            int decay = floor(rand() % 3);
            int pixelBelowIntensity = firePixelsArray[pixelBelowIndex];
            int intensity = pixelBelowIntensity - decay >= 0 ? pixelBelowIntensity - decay : 0;
            int position  = (pixel - decay >= 0) ? pixel - decay : 0;
            firePixelsArray[position] = intensity;
        }
    }

    void Render() {
        Clear(olc::BLACK);
        for (int x = 0; x < WINDOW_WIDTH; x++) {
            for (int y = 0; y < WINDOW_HEIGHT; y++) {
                int pixel = x + (WINDOW_WIDTH * y);
                int fireIntensity = firePixelsArray[pixel];
                uint8_t r = fireColoursPalette[fireIntensity][0];
                uint8_t g = fireColoursPalette[fireIntensity][1];
                uint8_t b = fireColoursPalette[fireIntensity][2];
                olc::Pixel col = {r, g, b, 255};
                FillRect(x, y, 1, 1, col);
            }
        }
    }

    bool OnUserDestroy() override {
        delete[] firePixelsArray;
        return true;
    }
private:
    float m_timeAccumilator = 0.0f;
};

int main(int argc, char** argv) {
    FireSim app;
    if (app.Construct(WINDOW_WIDTH, WINDOW_HEIGHT, 4, 4))
        app.Start();
    return 0;
}
