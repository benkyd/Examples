#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "rect.h"

#include <iostream>

bool isHoverd = false;

class RaysApp : public olc::PixelGameEngine {
public:
    RaysApp() 
        : rect() {
        sAppName = "Rays";
    }

    bool OnUserCreate() override {
        rect.SetRect(100, 100, 200, 100);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
        Clear(olc::BLACK);
        if (rect.Contains(new Vec2<int>(GetMouseX(), GetMouseY()))) {
            FillRect(rect.x, rect.y, rect.w, rect.h, olc::RED);
        } else {
            DrawRect(rect.x, rect.y, rect.w, rect.h, olc::RED);
        }

        std::cout << "MouseX: " << GetMouseX() << " MouseY: " << GetMouseY() << std::endl;
		return true;
	}
    Rect rect;
};

int main(int argc, char** argv) {
	RaysApp app;
	if (app.Construct(500, 300, 2, 2))
		app.Start();
    return 0;
}
