#include <raylib.h>
#include <algorithm>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MOVE_SPEED 3.0f
#define SPRITE_SCALE 3

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tower Defense");
  SetTargetFPS(60);

  Image playerImage = LoadImage("../assets/player.png");
  Texture2D PlayerTexture = LoadTextureFromImage(playerImage);
  UnloadImage(playerImage);

  float playerRotation = 60.0;
  float targetRotation = 0.0f;

  Vector2 playerPos = {
    (float)SCREEN_WIDTH/2,
    (float)SCREEN_HEIGHT/2
  };

  while (!WindowShouldClose()) {

      if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        playerPos.x += MOVE_SPEED;
        targetRotation = 90.0f;
      }
      if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        playerPos.x -= MOVE_SPEED;
        targetRotation = -90.0f;
      }
      if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        playerPos.y -= MOVE_SPEED;
        targetRotation = 0.0f;
      }
      if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        playerPos.y += MOVE_SPEED;
        targetRotation = 180.0f;
      }

      playerRotation += (targetRotation - playerRotation) * 0.1f;

      Rectangle src = {
        0,
        0,
        (float)PlayerTexture.width,
        (float)PlayerTexture.height
      };

      Rectangle dst = {
        playerPos.x,
        playerPos.y,
        (float)PlayerTexture.width * SPRITE_SCALE,
        (float)PlayerTexture.height * SPRITE_SCALE
      };

      Vector2 origin = {
        dst.width / 2,
        dst.height / 2
      };

    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawTexturePro(PlayerTexture, src, dst, origin, playerRotation, WHITE);
    EndDrawing();
  }

  CloseWindow();
}