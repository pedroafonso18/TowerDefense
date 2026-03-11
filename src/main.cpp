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
  Vector2 cratePos = {
    0.0f,
    0.0f
  };
  bool crateShouldFollowPlayer = false;

  while (!WindowShouldClose()) {
    player.HandleMovement();

    Rectangle crateRect = {
      cratePos.x,
      cratePos.y,
      (float)CrateTexture.width,
      (float)CrateTexture.height
    };

    if (IsKeyPressed(KEY_E) && CheckCollisionRecs(player.GetRectangle(), crateRect)) {
        crateShouldFollowPlayer = true;
    }
    

    if (crateShouldFollowPlayer) {
      cratePos = {
        player.GetPosition().x - CrateTexture.width * 0.5f,
        player.GetPosition().y - CrateTexture.height * 0.5f
      };
    }

    BeginDrawing();
      ClearBackground(RAYWHITE);
      player.Draw();
      DrawText(TextFormat("X: %.1f\nY: %.1f", player.GetPosition().x, player.GetPosition().y), 580, 0, 22, BLACK);      
      DrawTextureV(CrateTexture, cratePos, WHITE);
    EndDrawing();
  }

  CloseWindow();
}