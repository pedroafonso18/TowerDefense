#ifndef INCLUDE_CRATE_H
#define INCLUDE_CRATE_H

#include <raylib.h>
#include "../include/Player.h"
#include "../include/Hole.h"

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
      Player& player,
      Hole& hole
    );

    bool IsIntersectingWithHole(
      Hole& hole
    );

  private:
    Texture crateTexture;
    Vector2 position;
    bool canDrawCrate = true;
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