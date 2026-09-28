#include <stdio.h>
#include <raylib.h>

#define WIDTH 800
#define HEIGHT 600

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Game of Life");

    while (!WindowShouldClose()) {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
