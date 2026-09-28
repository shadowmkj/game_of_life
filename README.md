# Game of Life

A simple implementation of Conway's Game of Life in C using [raylib](https://www.raylib.com/).

Reference: [Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## Prerequisites

- C compiler (`clang` or `gcc`)
- `raylib` (macOS via Homebrew: `brew install raylib`)
- [just](https://github.com/casey/just) (optional task runner)

## Building and Running

### Using `just`

```sh
# Build and run
just run

# Or build only
just build
```

### Manual Compilation

```sh
cc -o main main.c -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib \
    -framework CoreVideo -framework IOKit -framework Cocoa \
    -framework GLUT -framework OpenGL

./main
```

## Controls

- **Left Mouse Button (Click / Drag)**: Place / activate living cells
- **Right Mouse Button (Click / Drag)**: Erase / deactivate cells
- **Spacebar**: Toggle animation (play / pause)
- **Escape / Close Window**: Exit
