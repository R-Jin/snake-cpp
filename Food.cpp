#include "Food.hpp"
#include <iostream>
#include <vector>

Food::Food(int foodWidth, int cellCount) {
    this -> foodWidth = foodWidth;
    this -> cellCount = cellCount;
    this -> pos       = GenerateRandomPos(cellCount);
}

void Food::Draw() {
    DrawRectangle(pos.x * foodWidth, pos.y * foodWidth, foodWidth, foodWidth, RED);
}

Vector2Int Food::GenerateRandomPos(int cellCount, std::deque<Vector2Int> parts) {
    // std::vector<Vector2> possible;

    // Generate possible coordinates
    // int x, y;
    // for (int i = 0; i < cellCount; i++) {
    //     for (int j = 0; j < cellCount; j++) {
    //         for (Vector2 part : parts) {
    //             x = i, y = j;
    //             if (x == part.x && y == part.y)
    //                 possible.push_back(Vector2{ static_cast<float>(x), static_cast<float>(y) });
    //         }
    //     }
    // }
    
    int x = GetRandomValue(0, cellCount - 1);
    int y = GetRandomValue(0, cellCount - 1);

    return Vector2Int( x, y );
}