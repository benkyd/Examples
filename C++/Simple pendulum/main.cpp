#include <iostream>
#include <sstream>
#include <math.h>

#include "rect.h"

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#define PI 3.14159265359

class SimplePendulum : public olc::PixelGameEngine {
public:
    SimplePendulum() {
        sAppName = "Simple Pendulum";
    }

    bool OnUserCreate() override {
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        /* START CALCULATONS */
        if (!m_isStopped) {
            m_timeAccumilator = m_timeAccumilator + fElapsedTime;
            if (m_timeAccumilator >= 0.016f) {
                m_aAccel = ((-1 * m_gravity / m_pLength) * sin(m_theta) * m_pMass) * m_timeAccumilator;
                m_timeAccumilator = 0.0f;

                m_aVelocity += m_aAccel;
                m_aVelocity *= m_pDamping;
                m_theta += m_aVelocity;
            }
        }

        m_x = m_pLength * sin(m_theta) + m_pivotX;
        m_y = m_pLength * cos(m_theta) + m_pivotY;
        /* END CALCULATIONS */
        draw();

        std::stringstream angularVel;
        angularVel << "Angular velocity: " << m_aVelocity;
        DrawString(0, 0, angularVel.str(), olc::BLACK);
        std::stringstream angularAccel;
        angularAccel << "Angular acceleration: " << m_aAccel;
        DrawString(0, 10, angularAccel.str(), olc::BLACK);
        std::stringstream coords;
        coords << "Pendulum bob pos X:" << m_x << " Y: " << m_y;
        DrawString(0, 20, coords.str(), olc::BLACK);

        Rect p;
        p.SetRect(m_x - 40, m_y - 40, 80, 80);
        if (p.Contains(Vec2<int>(GetMouseX(), GetMouseY()))) {
            DrawRect(p.x, p.y, p.w, p.h, olc::DARK_MAGENTA);
            if (GetMouse(0).bHeld) {
                m_isStopped = true;
                m_theta = atan2(GetMouseX() - m_pivotX, GetMouseY() - m_pivotY);
                m_aAccel = 0.0f;
                m_aVelocity = 0.0f;
            }  else {
                m_isStopped = false;
            }
        } else {
            DrawRect(p.x, p.y, p.w, p.h, olc::RED);
            m_isStopped = false;
        }

        return true;
    }

    void draw() {
        Clear(olc::WHITE);
        FillCircle(m_pivotX, m_pivotY, 8, olc::RED);
        DrawLine(m_pivotX, m_pivotY, m_x, m_y, olc::BLACK);
        FillCircle(m_x, m_y, 20, olc::BLACK);
    }
private:
    bool m_isStopped = false;
    float m_theta = PI / 4;

    float m_pivotX = 500;
    float m_pivotY = 20;
    float m_x = 500;
    float m_y = 220;

    float m_pLength = 300;

    float m_aVelocity = 0.0f;
    float m_aAccel = 0.0f;

    float m_gravity = 9.81;
    float m_pMass = 5;

    float m_pDamping = 0.999999999;
    float m_timeAccumilator = 0.0f;
};

int main(int argc, char** argv) {
    SimplePendulum app;
    if (app.Construct(1000, 600, 1, 1)) 
        app.Start();
    return 0;
}
