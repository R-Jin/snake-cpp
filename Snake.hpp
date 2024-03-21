#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>
#include <deque>
#include "Util.hpp"

class Snake {
    public:
        int snakeWidth;
        int cellCount;
        Vector2Int direction; // Store direction of snake in {dx, dy}

        // Store the snakes part coordinates in a double ended queue
        std::deque<Vector2Int> parts;

        // Snake Constructor
        Snake(int snakeWidth, int cellCount);

        // Used to update the snake
        void Update(bool ateApple);

        // Check if snake has collided with itself
        bool Collided();

        // Reset snake after collision
        void Reset();

        // Draw the snake
        void Draw();
};

#endif