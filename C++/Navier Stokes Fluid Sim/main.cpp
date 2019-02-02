#include <string>

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#define N 600
#define SIZE (N + 2) * (N + 2)
#define IX(i,j) ((i)+(N+2)*(j))

class NavierStokes : public olc::PixelGameEngine {
public:
    NavierStokes() {
        sAppName = "Fluid Dynamics";
    }

    bool OnUserCreate() override {
        return true;
		memset(u, 0, sizeof(float) * SIZE);
		memset(v, 0, sizeof(float) * SIZE);
		memset(u_prev, 0, sizeof(float) * SIZE);
		memset(v_prev, 0, sizeof(float) * SIZE);
		memset(dens, 0, sizeof(float) * SIZE);
		memset(dens_prev, 0, sizeof(float) * SIZE);

    };

    bool OnUserUpdate(float fElapsedTime) override {
        Clear(olc::WHITE);

		

        return true;
    }
private:
	float u[SIZE], v[SIZE], u_prev[SIZE], v_prev[SIZE];
	float dens[SIZE], dens_prev[SIZE];

};

int main(int argc, char** argv) {
    NavierStokes app;
    if (app.Construct(600, 600, 1, 1)) {
        app.Start();
    }
    return 0;
}   
