#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <iostream>
#include <stack>

typedef enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
} Direction;

struct Cell {
    bool visited = false;
    int width = 3;
};

class Maze : public olc::PixelGameEngine {
public:
    Maze() 
        : m_mazeDimensions(50, 50) {
        sAppName = "Maze";
    }

    bool OnUserCreate() {
        m_maze = new Cell[m_mazeDimensions.x * m_mazeDimensions.y];
        m_maze[0].visited = true;
        m_stack.push({0, 0});
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) {


        draw();

        return true;
    }

    void draw() {

        for (int x = 0; x < m_mazeDimensions.x; x++) {
            for (int y = 0; y < m_mazeDimensions.y; y++) {
                int index = x + y * m_mazeDimensions.x;
                int width = m_maze[index].width;

                if (m_maze[index].visited) {
                    DrawRect(x + m_mazeDimensions.x * width, y + m_mazeDimensions.y * width, width, width, olc::BLACK);
                } else {
                    DrawRect(x + m_mazeDimensions.x * width, y + m_mazeDimensions.y * width, width, width, olc::RED);
                }
            }
        }

    }
private:
    std::stack<Vec2<int>> m_stack;
    Vec2<int> m_mazeDimensions;
    Cell* m_maze;
};

int main(int argc, char** argv) {
    Maze maze;
    maze.Construct(500,500,2,2);
    maze.Start();
    // return 0;
}
