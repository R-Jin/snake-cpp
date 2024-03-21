#include <iostream>
#include <raylib.h>
#include "Food.hpp"
#include "Snake.hpp"
#include <string>

int cellSize = 30;
int cellCount = 40;


int main() {
    std::cout << "starting the game ..." << std::endl;
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake");

    Food food = Food(cellSize, cellCount);
    Snake snake = Snake(cellSize, cellCount);

    int score{ 0 };

    SetTargetFPS(60);
    int frameCounter{ 0 };
    int key;
    bool ateFood{ false };

    while(WindowShouldClose() == false) {

        // Handle input
        if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1) {
            snake.direction = Vector2Int(0, 1);
        }

        if (IsKeyPressed(KEY_UP) && snake.direction.y != 1) {
            snake.direction = Vector2Int(0, -1);
        }

        if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1) {
            snake.direction = Vector2Int(-1, 0);
        }

        if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1) {
            snake.direction = Vector2Int(1, 0);
        }

        // Update 4 times every second
        ++frameCounter;
        if (frameCounter % 5 == 0) {
            // Update

            ateFood = food.pos == snake.parts.front();
            snake.Update(ateFood);

            if (ateFood) {
                ++score;
                food.pos = food.GenerateRandomPos(cellCount, snake.parts);
            }

            frameCounter = 0;

            if (snake.Collided()) {
                snake.Reset();
                score = 0;
            }
        }

        // Drawing
        BeginDrawing();

        ClearBackground(BLACK);

        food.Draw();
        snake.Draw();

        DrawText(TextFormat("Score: %i", score), 50, 40, 40, WHITE);

        EndDrawing();

    }

    CloseWindow();
    return 0;
}