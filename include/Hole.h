#ifndef INCLUDE_HOLE_H
#define INCLUDE_HOLE_H

#include <raylib.h>

class Hole {
  public:
    Hole();

    Rectangle GetRectangle();

    void Draw();
  private:
    Texture holeTexture;
    Vector2 position;
};

#endif