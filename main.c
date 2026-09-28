#include <stdio.h>
#include <raylib.h>

#define ROWS 20
#define COLS 40
#define SIZE 20

// Define Global Grid
int grid[ROWS][COLS];
int next[ROWS][COLS]; // For double buffering

void update_grid() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int adj = 0; // Moore Adjacent Cells = 0

            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {

                    if (dc == 0 && dr == 0)
                        continue;

                    int nr = i + dr;
                    int nc = j + dc;

                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS) {
                        adj += grid[nr][nc];
                    }
                }
            }

            if (grid[i][j]) {
                next[i][j] = (adj == 2) || (adj == 3);
            } else {
                next[i][j] = (adj == 3);
            }
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = next[i][j];
        }
    }
}

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

    float acc = 0.0f;
    float step = 0.1f;

    bool animate = false;

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

        if (IsKeyPressed(KEY_SPACE)) {
            animate = !animate;
        }

        // State Update
        acc += GetFrameTime();
        if (acc >= step) {
            acc -= step;
            if (animate)
                update_grid();
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
