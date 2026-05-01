## SFML Entity Component Manager (ECM)
A lightweight, high-performance Entity Component Manager designed specifically for 2D game development with SFML (Simple and Fast Multimedia Library). This system decouples game data from logic, utilizing a Data-Oriented Design (DOD) approach to maximize cache coherency while keeping rendering and physics updates blazingly fast.

## Features
Seamless SFML Integration: Perfectly suited for managing sf::Sprite, sf::Shape, and sf::Transformable objects as pure data components.

Fast Component Lookup: Utilizes contiguous memory pools to ensure fast iteration during your SFML Update and Draw loops.

Flexible Entity Management: Create, recycle, and destroy entities seamlessly using unique IDs (e.g., uint32_t).

Type-Safe API: Templated architecture ensures safe and intuitive component assignment.

## Core Concepts
Entity: A simple unique identifier. It acts as a key to look up data, holding no methods or state itself.

Component: Plain Old Data (POD) structures representing specific attributes (e.g., sf::Vector2f for position, sf::Sprite for visuals).

Manager: The central registry that maps Entity IDs to their respective Component data pools and handles entity lifecycles.

## Quick Start & Game Loop Example
Here is how you can use the ECM to drive a standard SFML game loop, separating your physics logic from your rendering logic.
## How to Use:
When building your SFML game with this manager, it is highly recommended to split your logic into distinct Systems:

InputSystem: Reads sf::Keyboard or sf::Mouse and updates Velocity components.

PhysicsSystem: Iterates over all entities with Transform and Velocity components and applies movement based on dt.

 CollisionSystem: Checks sf::FloatRect intersections between entities that possess a Collider component.

 RenderSystem: Iterates over entities with Transform and Renderable components, syncs their positions, and calls window.draw().

## Installation
Add EntityManager.h and EntityManager.cpp to your SFML project directory.

Ensure you are linking against the standard SFML modules (sfml-graphics, sfml-window, sfml-system).

Compile using C++17 or higher.
