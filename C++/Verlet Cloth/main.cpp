#include <iostream>
#include <vector>

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

struct Vec2f {
    float x, y;
};

struct MassPoint {
    Vec2f sPosition;
    Vec2f sVelocity;

    void step() {
        sPosition.x += sVelocity.x;
        sPosition.y += sVelocity.y;
    }
};

class VerletCloth : public olc::PixelGameEngine {
public:
    std::vector<MassPoint> sPoints;

    VerletCloth() {
        sAppName = "Verlet Cloth Simulation";
    }

    bool OnUserCreate() override {

        sPoints.push_back({{ 100.0f, 100.0f }, { 1.0f, 4.0f }});
        
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        Clear(olc::WHITE);

        m_fTimeCounter += fElapsedTime;

        if (m_fTimeCounter >= 0.016f) {
            m_fTimeCounter = 0.0f;
            for (auto& sPoint : sPoints){
                sPoint.step();
                FillRect(sPoint.sPosition.x, sPoint.sPosition.y, 4, 4, olc::BLACK);
            }
        }

        return true;
    }
private:
    float m_fTimeCounter = 0.0f;
};

int main(int argc, char** argv) {
    VerletCloth app;

    app.Construct(1000, 600, 1, 1);
    app.Start();

    return 0;
}
