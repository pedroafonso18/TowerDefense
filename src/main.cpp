#include <raylib.h>
#include "../include/Constants.h"
#include "../include/Player.h"
#include "../include/Crate.h"
#include "../include/Hole.h"

using namespace GameConst;

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tower Defense");
  SetTargetFPS(60);

  Player player;
  Crate crate;
  Hole hole;

  float targetRotation = 0.0f;

  while (!WindowShouldClose()) {
    player.HandleMovement();
    
    crate.HandleCrate(player, hole);

    BeginDrawing();
      ClearBackground(RAYWHITE);
      hole.Draw();
      crate.SpawnCrate();
      player.Draw();
      DrawText(TextFormat("X: %.1f\nY: %.1f", player.GetPosition().x, player.GetPosition().y), 580, 0, 22, BLACK);
    EndDrawing();
  }

  CloseWindow();
}