#ifndef INCLUDE_CRATE_SPAWNER_H
#define INCLUDE_CRATE_SPAWNER_H

#include "../ThirdParty/timer.h"
#include "Crate.h"
#include <mutex>

class CrateSpawner {
  public:
    CrateSpawner();
    ~CrateSpawner();

    static void HandleCrateSpawning();
    void UpdateCrates();
    
    std::vector<Crate>& GetCrateVec();
  private:
    Timer timer;
    static std::mutex crateMutex;
    static std::vector<Vector2> pendingPositions;
    static std::vector<Crate> crateVec;
};

#endif