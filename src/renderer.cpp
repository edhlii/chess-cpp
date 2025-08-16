#include "renderer.h"

void Renderer::drawBoard() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      int posX = i * Game::CELL_SIZE;
      int posY = j * Game::CELL_SIZE;
      Color cellColor = (i + j) % 2 == 0 ? WHITE : BLACK;
      DrawRectangle(posX, posY, Game::CELL_SIZE, Game::CELL_SIZE, cellColor);
    }
  }
}