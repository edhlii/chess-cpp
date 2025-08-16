#include "raylib.h"
#include "resource_dir.h"  // utility header for SearchAndSetResourceDir

int main() {
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
  InitWindow(1280, 800, "Chess");
  SearchAndSetResourceDir("resources");
  Texture wabbit = LoadTexture("Chess.png");
  while (!WindowShouldClose()) {
    BeginDrawing();
    {
      ClearBackground(BLACK);
      DrawText("This is a test", 200, 200, 20, WHITE);
      DrawTexture(wabbit, 400, 200, WHITE);
    }
    EndDrawing();
  }
  UnloadTexture(wabbit);
  CloseWindow();
}
