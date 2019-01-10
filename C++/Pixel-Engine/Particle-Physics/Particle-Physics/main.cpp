#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <synchapi.h> // For Sleep(int ms)
#include <vector>     // for std::vector
#include <thread>     // for std::thread
#include <mutex>      // for std::mutex
#include <atomic>     // for std::atomic

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

#define CONSTANT_GRAVITY 9.8

static unsigned long PHYSICS_UPDATE_RATE = 16; // Ms per update

std::atomic<bool> isPhysicsRunning = false;

class Particle {
public:
	Particle() {};
	void Render() {};
};

std::mutex PhysicsMutex;
std::vector<Particle> Particles;

void RunPhysics() {
	while (isPhysicsRunning) {
		std::cout << 1 << std::endl;



		Sleep(PHYSICS_UPDATE_RATE);
	}
}

class ParticlePhysics : public olc::PixelGameEngine {
public:
	ParticlePhysics() {
		sAppName = "Particle Physics Thing";
	}

	bool OnUserCreate() override {
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(25, 25, 25));

		isPhysicsRunning = true;
		m_physicsThread = new std::thread(&RunPhysics);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		PhysicsMutex.lock();
		for (unsigned int i = 0; i < Particles.size(); i++) {
			Particles[i].Render();
		}
		PhysicsMutex.unlock();

		return true;
	}

	void DestroyPhysics() {
		isPhysicsRunning = false;
		m_physicsThread->join();
	}
private:
	std::thread* m_physicsThread;
};


int main(int argc, char** argv) {
	ParticlePhysics demo;
	if (demo.Construct(WINDOW_WIDTH, WINDOW_HEIGHT, 2, 2))
		demo.Start();
	return 0;
}
