#include <iostream>
#include <sstream>
#include <vector>

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

const float GRAVITY = 5.81f;
const float    DRAG = 0.99f;

struct Vec2f {
    float x, y;
};

struct MassPoint {
    Vec2f sPosition;
    bool bLocked = false; // If true, the point will not be able to move

    MassPoint(Vec2f sPos)
        : sPosition(sPos),
          sLastPosition(sPos) {  }

    void step() {
        if (bLocked) return;
        // Inertia
        Vec2f sVelocity;
        sVelocity.x = sPosition.x - sLastPosition.x * DRAG;
        sVelocity.y = sPosition.y - sLastPosition.y * DRAG;
        
        sPosition.x += sVelocity.x; 
        sPosition.y += sVelocity.y + GRAVITY; 

        sLastPosition.x = sPosition.x;
        sLastPosition.y = sPosition.y;
    }
private:
    Vec2f sLastPosition;
};

class VerletCloth : public olc::PixelGameEngine {
public:
    std::vector<MassPoint> sPoints;

    VerletCloth() {
        sAppName = "Verlet Cloth Simulation";
    }

    bool OnUserCreate() override {

        sPoints.push_back({{ 1.0f, 1.0f }});
        
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {

        m_fTimeCounter += fElapsedTime;

        if (m_fTimeCounter >= 0.016f) {
            Clear(olc::WHITE);
            m_fTimeCounter = 0.0f;



            for (auto& sPoint : sPoints){
                std::stringstream str;
                str << "Pos: X:" << sPoint.sPosition.x << ":Y:" << sPoint.sPosition.y;
                DrawString(0, 0, str.str(), olc::BLACK);

                sPoint.step();
                FillRect(sPoint.sPosition.x, sPoint.sPosition.y, 4, 4, olc::BLACK);
            }
    
    
        }


        if (GetKey(olc::ESCAPE).bPressed)
            exit(0);

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
