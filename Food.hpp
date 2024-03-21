#ifndef FOOD_H
#define FOOD_H

#include <raylib.h>
#include <deque>
#include "Util.hpp"

class Food {
    public:
        int foodWidth;
        int cellCount;
        Vector2Int pos;

        Food(int foodWidth, int cellCount);

        void Draw();

        Vector2Int GenerateRandomPos(int cellCount, std::deque<Vector2Int> parts={}); 
};

#endif