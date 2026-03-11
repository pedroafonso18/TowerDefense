#include "../include/Player.h"
#include "../include/Constants.h"
#include "raylib.h"
#include <cmath>

Player::Player()
{
  Image playerImage = LoadImage("../assets/player.png");
  texture = LoadTextureFromImage(playerImage);
  UnloadImage(playerImage);
  position = {
    (float)GameConst::SCREEN_WIDTH/2,
    (float)GameConst::SCREEN_HEIGHT/2
  };
  rotation = 60.0f;
}

Texture Player::GetTexture() const 
{
  return texture;
}

Vector2 Player::GetPosition() const
{
  return position;
}

float Player::GetRotation() const
{
  return rotation;
}

void Player::SetPosition(
  Vector2 _position
)
{
  position = _position;
}

void Player::UpdateRotation(
  float targetRotation
)
{
  float delta = std::remainderf(targetRotation - rotation, 360.0f);
  rotation += delta * 0.1f;
}

void Player::Draw()
{
  Rectangle src = {
    0,
    0,
    (float)texture.width,
    (float)texture.height
  };

  Rectangle dst = {
    position.x,
    position.y,
    (float)texture.width * GameConst::SPRITE_SCALE,
    (float)texture.height * GameConst::SPRITE_SCALE
  };

  Vector2 origin = {
    dst.width / 2,
    dst.height / 2
  };

  DrawTexturePro(texture, src, dst, origin, rotation, WHITE);
}

void Player::HandleMovement()
{
  float targetRotation = 0.0f;
  if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
    targetRotation = 90.0f;
    SetPosition(Vector2({position.x + GameConst::MOVE_SPEED, position.y}));
  }
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
    targetRotation = -90.0f;
    SetPosition(Vector2({position.x - GameConst::MOVE_SPEED, position.y}));
  }
  if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
    targetRotation = 0.0f;
    SetPosition(Vector2({position.x, position.y - GameConst::MOVE_SPEED}));
  }
  if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
    targetRotation = 180.0f;
    SetPosition(Vector2({position.x, position.y + GameConst::MOVE_SPEED}));
  }

  UpdateRotation(targetRotation);
}

Rectangle Player::GetRectangle() const
{
  float playerW = texture.width + GameConst::SPRITE_SCALE;
  float playerH = texture.height + GameConst::SPRITE_SCALE;

  return {
    position.x - playerW * 0.5f,
    position.y - playerH * 0.5f,
    playerW,
    playerH
  };
}