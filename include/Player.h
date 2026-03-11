#ifndef INCLUDE_PLAYER_H
#define INCLUDE_PLAYER_H

#include <raylib.h>

class Player {
  public:
    Player();

    Texture GetTexture() const;

    Vector2 GetPosition() const;
    
    float GetRotation() const;
    
    void SetPosition(
      Vector2 _position
    );

    void Draw();

    void HandleMovement();

  private:
    
    Texture texture;
    Vector2 position;
    float rotation;
      
    void SetTexture(
      Texture _texture
    );

    void UpdateRotation(
      float targetRotation
    );
};

#endif