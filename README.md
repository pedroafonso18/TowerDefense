# Tower Defense

A simple top-down crate-carrying game built with **C++** and **[Raylib](https://www.raylib.com/)** as a fun personal project.

---

## Gameplay

You control a player character on a fixed 640×480 screen. Crates periodically appear at random positions around the map. Your goal is to pick them up and drop them into the hole (manhole) at the centre of the screen.

- **Crates spawn** automatically every **10 seconds** at a random location.
- Walk up to a crate and press **E** to pick it up. You can only carry one crate at a time.
- While carrying a crate, walk over the **hole** to deposit it — the crate despawns and you are free to fetch the next one.

---

## Controls

| Key | Action |
|-----|--------|
| W / ↑ | Move up |
| S / ↓ | Move down |
| A / ← | Move left |
| D / → | Move right |
| E | Pick up crate (when adjacent) |

The player sprite smoothly rotates to face the direction of movement.

---

## Project Structure

```
TowerDefense/
├── assets/
│   ├── player.png        # Player sprite
│   ├── crate.png         # Crate sprite
│   └── bueiro.png        # Hole / manhole sprite
├── include/
│   ├── Constants.h       # Game-wide constants (screen size, speed, etc.)
│   ├── Player.h          # Player class
│   ├── Crate.h           # Crate class
│   ├── Hole.h            # Hole class
│   └── CrateSpawner.h    # Timed crate spawning logic
├── src/
│   ├── main.cpp          # Entry point and main game loop
│   ├── Player.cpp
│   ├── Crate.cpp
│   ├── Hole.cpp
│   └── CrateSpawner.cpp
├── ThirdParty/
│   └── timer.h           # Async interval timer (© Ringo Hoffmann)
└── CMakeLists.txt
```

### Key Classes

| Class | Responsibility |
|-------|---------------|
| `Player` | Movement (WASD / arrows), smooth rotation, crate-holding state, rendering |
| `Crate` | Rendering, collision-based pickup (E key), following the player, despawning into the hole |
| `CrateSpawner` | Background thread timer that spawns new crates at random positions every 10 s |
| `Hole` | Static target at the screen centre; crates despawn when deposited here |

---

## Building

### Prerequisites

- **CMake 3.31** or newer
- A **C++ compiler** with C++17 support (GCC, Clang, MSVC)
- An internet connection (Raylib 5.0 is fetched automatically via CMake's `FetchContent`)

### Steps

```bash
# 1. Clone the repository
git clone https://github.com/pedroafonso18/TowerDefense.git
cd TowerDefense

# 2. Configure
cmake -B build

# 3. Build
cmake --build build

# 4. Run (from the build directory so asset paths resolve correctly)
cd build
./TowerDefense
```

> **Note:** The game loads assets from `../assets/` relative to the working directory, so it must be launched from inside the `build/` folder.

---

## Dependencies

| Dependency | Version | How it is obtained |
|------------|---------|--------------------|
| [Raylib](https://github.com/raysan5/raylib) | 5.0 | CMake `FetchContent` (downloaded at configure time) |
| [timer.h](https://github.com/zekroTJA/timer.h) | — | Vendored in `ThirdParty/` |

---

## License

This project was made for fun and is not under any formal license. The bundled `ThirdParty/timer.h` is © 2018 Ringo Hoffmann (zekro Development) — see [zekro.de/policy](https://zekro.de/policy) for its terms.
