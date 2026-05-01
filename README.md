## Entity Component Manager (ECM)

A lightweight and modular Entity Component System (ECS) manager designed to simplify game development by decoupling data (components) from behavior (systems).

## 🚀 Features
Simple and flexible ECS architecture
Fast entity creation and destruction
Easy component attachment and removal
Efficient querying of entities by components
Scalable for small to large games
📦 Installation
## Clone the repository:
git clone https://github.com/your-username/entity-component-manager.git
Add the source files to your project:
/src/ecm/
Include the main header/module in your game:
#include "ECM.h"
🧠 Core Concepts
1. Entity

A unique ID representing a game object.

Entity player = ecm.createEntity();
2. Component

Plain data attached to entities.

struct Position {
    float x, y;
};

struct Velocity {
    float dx, dy;
};
3. Adding Components
ecm.addComponent<Position>(player, {0.0f, 0.0f});
ecm.addComponent<Velocity>(player, {1.0f, 1.0f});
4. Getting Components
Position& pos = ecm.getComponent<Position>(player);
5. Removing Components
ecm.removeComponent<Velocity>(player);
6. Systems (Logic)

Systems operate on entities with specific components.

for (auto entity : ecm.getEntitiesWith<Position, Velocity>()) {
    auto& pos = ecm.getComponent<Position>(entity);
    auto& vel = ecm.getComponent<Velocity>(entity);

    pos.x += vel.dx;
    pos.y += vel.dy;
}
## 🎮 How to Use in Your Game
Step 1: Initialize ECM
ECM ecm;
Step 2: Create Entities
Entity player = ecm.createEntity();
Step 3: Attach Components
ecm.addComponent<Position>(player, {0, 0});
ecm.addComponent<Velocity>(player, {2, 3});
Step 4: Create Systems

Example: Movement system

void updateMovement(ECM& ecm) {
    for (auto entity : ecm.getEntitiesWith<Position, Velocity>()) {
        auto& pos = ecm.getComponent<Position>(entity);
        auto& vel = ecm.getComponent<Velocity>(entity);

        pos.x += vel.dx;
        pos.y += vel.dy;
    }
}
Step 5: Game Loop Integration
while (gameRunning) {
    updateMovement(ecm);
    render();
}
🧹 Destroying Entities
ecm.destroyEntity(player);
## ⚙️ Best Practices
Keep components data-only (no logic)
Keep systems focused and single-purpose
Avoid large “god systems”
Use multiple small systems instead of one big one
📁 Example Structure
/game
  /components
    Position.h
    Velocity.h
  /systems
    MovementSystem.cpp
  main.cpp
## 🛠 Future Improvements
Event system
Serialization (save/load)
Multithreading support
Debug tools
📄 License

MIT License
