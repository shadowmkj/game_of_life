#include <stdio.h>
#include <raylib.h>

#define ROWS 20
#define COLS 40
#define SIZE 20

// Define Global Grid
int grid[ROWS][COLS];

void draw_grid() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (grid[i][j]) {
                DrawRectangle(i * SIZE, j * SIZE, SIZE, SIZE, WHITE);
            }
            DrawRectangleLines(i * SIZE, j * SIZE, SIZE, SIZE, DARKGRAY);
        }
    }
}

int main(void) {
    InitWindow(COLS * SIZE, ROWS * SIZE, "Game of Life");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Input Handling
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) ||
            IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            Vector2 mouse = GetMousePosition();

            int x = mouse.x / SIZE;
            int y = mouse.y / SIZE;

            if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
                grid[x][y] = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
            }
        }

        // Render
        BeginDrawing();
        ClearBackground(BLACK);

        draw_grid();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
