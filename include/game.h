#pragma once
#include <map>
#include <string>

#include "raylib.h"
#include "renderer.h"
#include "resource_dir.h"  // utility header for SearchAndSetResourceDir

class Game {
 public:
  const static int WINDOW_WIDTH = 800;
  const static int WINDOW_HEIGHT = 800;
  const static int CELL_SIZE = 100;

  Game();
  ~Game();

  void run();

 private:
  std::map<std::string, Texture> textures;
  void loadTexture();
};