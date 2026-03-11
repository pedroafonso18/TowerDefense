#include <raylib.h>
#include "../include/Constants.h"
#include "../include/Player.h"

using namespace GameConst;

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tower Defense");
  SetTargetFPS(60);

  Player player;

  Image crateImage = LoadImage("../assets/crate.png");
  Texture2D CrateTexture = LoadTextureFromImage(crateImage);
  UnloadImage(crateImage);

  float targetRotation = 0.0f;

  while (!WindowShouldClose()) {
    player.HandleMovement();

    BeginDrawing();
      ClearBackground(RAYWHITE);
      player.Draw();
      DrawTexture(CrateTexture, 0,  0, WHITE);
    EndDrawing();
  }

  CloseWindow();
}