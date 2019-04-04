#include <iostream>
#include <sstream>
#include <vector>

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

const float GRAVITY = 5.81f;
const float    DRAG = 0.99f;

struct Link;
struct Vec2f {
    float x, y;
};

struct MassPoint {
    Vec2f sPosition;
    bool bLocked = false; // If true, the point will not be able to move
    float fMass;

    std::vector<Link*> sLinks;

    MassPoint(Vec2f sPos, float fMass)
        : sPosition(sPos),
          sLastPosition(sPos),
          fMass(fMass) {  }

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

    void solve() {

    }
private:
    Vec2f sLastPosition;
};

struct Link {
    float fRestingDistance;
    float fStiffness;
    float fTear;

    MassPoint* p0;
    MassPoint* p1;

    void solve() {
        float diffX = p0->sPosition.x - p1->sPosition.x;
        float diffY = p0->sPosition.y - p1->sPosition.y;
        float d = sqrt(diffX * diffX + diffY * diffY);
        
        float difference = (fRestingDistance - d) / d;
        
        float im1 = 1 / p0->fMass;
        float im2 = 1 / p1->fMass;
        float scalarP1 = (im1 / (im1 + im2)) * fStiffness;
        float scalarP2 = fStiffness - scalarP1;
        
        p0->sPosition.x += diffX * scalarP1 * difference;
        p0->sPosition.y += diffY * scalarP1 * difference;
        
        p1->sPosition.x -= diffX * scalarP2 * difference;
        p1->sPosition.y -= diffY * scalarP2 * difference;
    }

};

class VerletCloth : public olc::PixelGameEngine {
public:
    std::vector<MassPoint> sPoints;
    int iConstraintAccuracy;

    VerletCloth() {
        sAppName = "Verlet Cloth Simulation";
    }

    bool OnUserCreate() override {

        sPoints.push_back({{ 1.0f, 1.0f }, 1.0f});

        iConstraintAccuracy = 5;
        
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {

        m_fTimeCounter += fElapsedTime;

        if (m_fTimeCounter >= 0.016f) {
            Clear(olc::WHITE);
            m_fTimeCounter = 0.0f;

            for (int x = 0; x < iConstraintAccuracy; x++) {
                for (int i = 0; i < sPoints.size(); i++) {
                    MassPoint pointmass = sPoints[i];
                    pointmass.solve();
                }
            }


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

    void DrawLink(Link& link) {
        DrawLine(link.p0->sPosition.x, link.p0->sPosition.y,
                 link.p1->sPosition.x, link.p1->sPosition.y,
                 olc::RED);
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
