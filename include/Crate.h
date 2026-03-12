#ifndef INCLUDE_CRATE_H
#define INCLUDE_CRATE_H

#include <raylib.h>
#include "../include/Player.h"

class Crate {
  public:
    Crate();

    void SetPosition(
      Vector2 _position
    );

    Vector2 GetPosition();

    Rectangle GetRectangle();

    void SpawnCrate();

    void DespawnCrate();

    void HandleCrate(
      Player& player
    );

  private:
    Texture crateTexture;
    Vector2 position;
    bool isFollowingPlayer = false;

    void Draw();

    void HandleCratePickup(
      Player& player
    );

    void HandleCrateMovement(
      Player& player
    );
};
#endif