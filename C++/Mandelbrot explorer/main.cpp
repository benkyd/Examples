#include <iostream>
#include <numeric>
#include <cmath>
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
            long double mX = ((long double)pX - 1000.0f / 2.0f) / 100 * m_scale - 1 + m_x;
            #pragma omp parallel for schedule(dynamic)
            for (int pY = 0; pY < 600; pY++) {
                long double mY = (600.0f / 2.0f - (long double)pY) / 100 * m_scale - 1 + m_y;

                long double Zre = 0.0f; long double Zim = 0.0f;
                int iteration = 0;
                while ((Zre * Zre) + (Zim * Zim) <= 2 * 2 && iteration < m_maxIterations) {
                    long double tX = (Zre * Zre) - (Zim * Zim) + mX;
                    Zim = (2 * Zre * Zim) + mY;
                    Zre = tX;
                    iteration++;
                }
                long double ratio = (long double)iteration - std::log2(std::log2(Zre*Zre + Zim*Zim)) / m_maxIterations;
<<<<<<< HEAD
                olc::Pixel colour = olc::Pixel(ratio + 255.0f, ratio + 255.0f, ratio + 255.0f);
=======
                olc::Pixel colour = olc::Pixel(ratio, ratio, ratio);
>>>>>>> 447c0c7a41568e3993820342ea06d7b95d1fe18c
                DrawRect(pX, pY, 1, 1, colour);
            }
        }

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
    long double m_x = 1.0f;
    long double m_y = 1.0f;
    long double m_scale = 0.7f;
    int m_maxIterations = 100;
    std::map<int, olc::Pixel> m_palete;
};

int main(int argc, char** argv) {
    Mandelbrot app;

    app.Construct(1000, 600, 1, 1);
    app.Start();

    return 0;
}
