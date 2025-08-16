#include "game.h"

#include <filesystem>
#include <iostream>

Game::Game() {
  // Initialize game windows
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess");
  SearchAndSetResourceDir("resources");
  loadTexture();
}

Game::~Game() {
  for (auto &p : textures) {
    UnloadTexture(p.second);
  }
  CloseWindow();
}

void Game::loadTexture() {
  for (const auto &dirEntry :
       std::filesystem::recursive_directory_iterator("../resources/Pieces")) {
    std::string fileName = dirEntry.path().filename().string();
    std::string filePath = dirEntry.path().string();

    Image image = LoadImage(filePath.c_str());
    ImageResize(&image, CELL_SIZE, CELL_SIZE);
    Texture texture = LoadTextureFromImage(image);

    textures[fileName] = texture;
  }
}

void Game::run() {
  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    Renderer::drawBoard();

    EndDrawing();
  }
}