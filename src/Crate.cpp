#include "../include/Crate.h"
#include "../include/Constants.h"
#include "raylib.h"

Crate::Crate()
{
  Image crateImage = LoadImage("../assets/crate.png");
  crateTexture = LoadTextureFromImage(crateImage);
  UnloadImage(crateImage);

  position = {
    (float)GameConst::SCREEN_WIDTH/2,
    (float)GameConst::SCREEN_HEIGHT/2
  };
}

void Crate::SetPosition(
  Vector2 _position
)
{
  position = _position;
}

Vector2 Crate::GetPosition() {
  return position;
}

Rectangle Crate::GetRectangle() {
  return {
    position.x,
    position.y,
    (float)crateTexture.width,
    (float)crateTexture.height
  };
}

void Crate::SpawnCrate() {
  Draw();
}

void Crate::Draw() {
  DrawTextureV(crateTexture, position, WHITE);
}

void Crate::HandleCratePickup(
  Player& player
)
{
  if (IsKeyPressed(KEY_E) && CheckCollisionRecs(player.GetRectangle(), GetRectangle()) && !player.GetIsHoldingCrate()) {
    player.SetIsHoldingCrate(true);
    isFollowingPlayer = true;
  }
}

void Crate::HandleCrateMovement(
  Player& player
)
{
  if (isFollowingPlayer) {
    position = {
      player.GetPosition().x - crateTexture.width * 0.5f,
      player.GetPosition().y - crateTexture.height * 0.5f
    };
  }
}

void Crate::HandleCrate(
  Player& player
)
{
  HandleCratePickup(player);
  HandleCrateMovement(player);
}