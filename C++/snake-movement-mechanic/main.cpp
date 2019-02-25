#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <iostream>
#include <vector>

const int MAP_WIDTH = 40;
const int MAP_HEIGHT = 40;

struct Point {
    int x, y;
    bool isSnake;
};

typedef enum {
    DIRECTION_UP,
    DIRECTION_RIGHT,
    DIRECTION_DOWN,
    DIRECTION_LEFT
} SnakeDir;

int index(int x, int y) {
    return y * MAP_HEIGHT + x; 
}

class Snake : public olc::PixelGameEngine {
public:
    std::vector<Point> map;
    std::vector<Point> snake_stack;
    SnakeDir dir = DIRECTION_RIGHT;

    bool OnUserCreate() {
        // Loop over every point in the map column
        // by column and initialize them as points
        // in the 1d map vector
        for (int i = 0; i < MAP_WIDTH; i++) {
            for (int j = 0; j < MAP_HEIGHT; j++) {
                map.push_back({i, j, false});
            }
        }

        // Settup snake stack
        snake_stack.push_back({2, 3, true});
        snake_stack.push_back({3, 3, true});
        snake_stack.push_back({4, 3, true});
        snake_stack.push_back({5, 3, true});
        dir = DIRECTION_RIGHT;

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) {
        // Take input and change direction
        if (GetKey(olc::Key::W).bPressed)
            dir = DIRECTION_UP;
        if (GetKey(olc::Key::A).bPressed)
            dir = DIRECTION_LEFT;
        if (GetKey(olc::Key::S).bPressed)
            dir = DIRECTION_DOWN;
        if (GetKey(olc::Key::D).bPressed)
            dir = DIRECTION_RIGHT;

        // Push an element for the head 
        // dependant on the direction

        if (dir == DIRECTION_UP) {
            snake_stack.push_back({snake_stack.back().x, snake_stack.back().y - 1, true});
        }
        
        if (dir == DIRECTION_RIGHT) {
            snake_stack.push_back({snake_stack.back().x + 1, snake_stack.back().y, true});
        }

        if (dir == DIRECTION_DOWN) {
            snake_stack.push_back({snake_stack.back().x, snake_stack.back().y + 1, true});
        }

        if (dir == DIRECTION_LEFT) {
            snake_stack.push_back({snake_stack.back().x - 1, snake_stack.back().y, true});
        }

        // Pop last element of the tail

        snake_stack.erase(snake_stack.begin());

        updateSnake();
        draw();
        return true;
    }

    void updateSnake() {
        // Set every map point to no snake
        for (int i = 0; i < map.size(); i++) {
            map[i].isSnake = false;
        }

        // Set the points that the snake are in in the map
        // to have a snake in
        for (int i = 0; i < snake_stack.size(); i++) {
            map[index(snake_stack[i].x, snake_stack[i].y)].isSnake = true;            
        }
    }

    void draw() {
        // Loop over every element in the map
        // and draw them on the map in their respective
        // screen position
        for (int i = 0; i < MAP_WIDTH; i++) {
            for (int j = 0; j < MAP_HEIGHT; j++) {
                if (map[index(i, j)].isSnake) {
                    DrawRect(i, j, 1, 1, olc::RED);
                } else {
                    DrawRect(i, j, 1, 1, olc::BLUE);
                }
            }
        }
    }
};

int main(int argc, char** argv) {
    Snake app;
    app.Construct(MAP_WIDTH, MAP_HEIGHT, 20, 20);
    app.Start();
    return 0;
}
