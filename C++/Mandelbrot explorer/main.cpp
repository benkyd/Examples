#include <iostream>
#include <map>

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Mandelbrot : public olc::PixelGameEngine {
public:
    Mandelbrot() {
        sAppName = "Mandelbrot set";
    }

    bool OnUserCreate() override {
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        #pragma omp parallel for schedule(dynamic)
        for (int pX = 0; pX < 1000; pX++) {
            float mX = ((float)pX - 1000.0f / 2.0f) / 100 * m_scale - 1 + m_x;
            #pragma omp parallel for schedule(dynamic)
            for (int pY = 0; pY < 600; pY++) {
                float mY = (600.0f / 2.0f - (float)pY) / 100 * m_scale - 1 + m_y;

                float x = 0.0f; float y = 0.0f;
                int iteration = 0;
                while ((x * x) + (y * y) <= 2 * 2 && iteration < m_maxIterations) {
                    float tX = (x * x) - (y * y) + mX;
                    y = (2 * x * y) + mY;
                    x = tX;
                    iteration++;
                }
                olc::Pixel colour = olc::Pixel(iteration * 2, iteration * 2, iteration * 2);
                DrawRect(pX, pY, 1, 1, colour);
            }
        }
        // m_scale -= 0.01f;

        if (GetKey(olc::Key::W).bHeld)
            m_y *= 1.01f;
        if (GetKey(olc::Key::S).bHeld)
            m_y /= 1.01f;
        if (GetKey(olc::Key::D).bHeld)
            m_x *= 1.01f;
        if (GetKey(olc::Key::A).bHeld)
            m_x /= 1.01f;
        if (GetKey(olc::Key::DOWN).bHeld)
            m_scale *= 1.01f;
        if (GetKey(olc::Key::UP).bHeld)
            m_scale /= 1.01f;

        std::cout << "Render time: " << fElapsedTime << std::endl;
        return true;
    }
private:
    float m_x = 1.0f;
    float m_y = 1.0f;
    float m_scale = 0.7f;
    int m_maxIterations = 100;
    std::map<int, olc::Pixel> m_palete;
};

int main(int argc, char** argv) {
    Mandelbrot app;

    app.Construct(1000, 600, 1, 1);
    app.Start();

    return 0;
}
