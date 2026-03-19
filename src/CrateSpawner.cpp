#include "../include/CrateSpawner.h"
#include "../include/Crate.h"
#include "../include/Constants.h"

#include <random>

std::mutex CrateSpawner::crateMutex{};
std::vector<Vector2> CrateSpawner::pendingPositions{};
std::vector<Crate> CrateSpawner::crateVec{};

CrateSpawner::CrateSpawner()
{
  timer.setInterval(GameConst::CRATE_SPAWN_INTERVAL);
  timer.setFunc(HandleCrateSpawning);
  timer.start();
}

CrateSpawner::~CrateSpawner() {
  timer.stop();
}

void CrateSpawner::HandleCrateSpawning() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrX(1, GameConst::SCREEN_WIDTH);
  std::uniform_int_distribution<> distrY(1, GameConst::SCREEN_HEIGHT);

  Vector2 position{
    .x = (float)distrX(gen),
    .y = (float)distrY(gen)
  };

  std::lock_guard<std::mutex> lock(crateMutex);
  pendingPositions.push_back(position);
}

void CrateSpawner::UpdateCrates() {
  std::lock_guard<std::mutex> lock(crateMutex);

  for (const auto& position : pendingPositions) {
    Crate crate;
    crate.SetPosition(position);
    crateVec.push_back(crate);
  }

  pendingPositions.clear();
}

std::vector<Crate>& CrateSpawner::GetCrateVec() {
  return crateVec;
}