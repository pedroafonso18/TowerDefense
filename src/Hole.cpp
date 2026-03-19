#include "../include/Hole.h"
#include "../include/Constants.h"
#include "raylib.h"

Hole::Hole()
{
  Image holeImage = LoadImage("../assets/bueiro.png");
  holeTexture = LoadTextureFromImage(holeImage);
  UnloadImage(holeImage);

  position = {
    (float)GameConst::SCREEN_WIDTH/2,
    (float)GameConst::SCREEN_HEIGHT/2
  };
}

Rectangle Hole::GetRectangle() {
    return {
    position.x,
    position.y,
    (float)holeTexture.width,
    (float)holeTexture.height
  };
}

void Hole::Draw() {
    Rectangle src = {
    0,
    0,
    (float)holeTexture.width,
    (float)holeTexture.height
  };

  Rectangle dst = {
    position.x,
    position.y,
    (float)holeTexture.width * GameConst::SPRITE_SCALE,
    (float)holeTexture.height * GameConst::SPRITE_SCALE
  };

  Vector2 origin = {
    dst.width / 2,
    dst.height / 2
  };

  DrawTexturePro(holeTexture, src, dst, origin, 0, WHITE);
}