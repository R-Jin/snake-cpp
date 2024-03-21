#include "Snake.hpp"
#include <iterator>

Snake::Snake(int snakeWidth, int cellCount) {
    this -> snakeWidth = snakeWidth;
    this -> cellCount = cellCount;
    this -> direction = {1, 0};
    this -> parts = {{cellCount / 2, cellCount / 2}};
}


void Snake::Update(bool ateApple) {
    // Calculate where the head of the snake should be
    Vector2Int newHead;
    Vector2Int oldHead = parts.front();

    newHead = oldHead + direction;

    if (newHead.x < 0) {
        newHead.x = cellCount - 1;
    }
    if (newHead.x >= cellCount) {
        newHead.x = 0;
    }
    if (newHead.y < 0) {
        newHead.y = cellCount - 1;
    }
    if (newHead.y >= cellCount) {
        newHead.y = 0;
    }

    if (!ateApple) {
        parts.pop_back();
    }

    parts.push_front(newHead);
}

bool Snake::Collided() {
    Vector2Int head = parts.front();

    auto body = parts.begin();
    ++body;

    for (auto it = body; it != parts.end(); ++it) {
        Vector2Int part = *it;

        if (head == part) {
            return true;
        }
    }
    return false;
}

void Snake::Reset() {
    direction = {1, 0};
    parts = {{cellCount / 2, cellCount / 2}};
}

void Snake::Draw() {
    for (Vector2Int part : parts ) {
        DrawRectangle(snakeWidth * part.x, snakeWidth * part.y, snakeWidth, snakeWidth, GREEN);
    }
}