# The Lost

## Description
The Lost is a text-based adventure game where players navigate through various scenarios and make choices to progress in the story. The game immerses players in a fictional world filled with challenges, puzzles, and exciting encounters. It offers an engaging narrative with multiple paths and outcomes based on the player's decisions.

## Features
- Engaging storyline with multiple paths and outcomes
- Text-based interface for immersive gameplay
- Various scenarios and challenges to overcome
- Decision-based gameplay with consequences
- Object-oriented design for modularity and extensibility
- Linked lists for efficient management of game objects

## How to Play
1. Launch the game on your preferred platform.
2. Read the story prompts and choose an option by entering the corresponding number or keyword.
3. Make decisions carefully as they may affect the outcome of the game.
4. Explore different paths and scenarios to uncover the full story.
5. Solve puzzles, overcome challenges, and interact with characters to progress in the game.
6. Enjoy the immersive experience and discover the different endings based on your choices.

## Object-Oriented Concepts
The game utilizes object-oriented concepts to organize and structure the codebase. Here are some examples of how these concepts were used:

1. **Classes**: The game is built around classes that represent various objects and entities in the game world, such as `Player`, `Scenario`, `Choice`, and `Item`. Each class encapsulates its own data and behavior, allowing for easier maintenance and extensibility.

2. **Inheritance**: Inheritance is used to create specialized classes based on more general classes. For example, the `Choice` class may have subclasses like `CombatChoice` or `PuzzleChoice`, which inherit common properties and behaviors from the base class.

3. **Encapsulation**: Encapsulation is employed to encapsulate related data and methods within classes, allowing for better organization and abstraction. For instance, the `Player` class may encapsulate attributes like health, inventory, and methods for interacting with the game world.

4. **Polymorphism**: Polymorphism is utilized to define common interfaces and behaviors across different classes. This enables objects of different classes to be used interchangeably, promoting code reuse and flexibility.

## Linked Lists in the Game
Linked lists play a crucial role in managing game objects efficiently. For example, a linked list can be used to represent the inventory of the player, where each item is stored as a node in the list. This data structure allows for dynamic addition and removal of items, ensuring efficient memory utilization.

By using linked lists, the game can easily handle operations such as adding or removing items from the inventory, iterating over the items, or searching for a specific item. The linked list's flexibility and dynamic nature make it an ideal choice for managing collections of objects in the game.


## Screenshots

![](../Hackathon3.0-Story-Based/images/The Lost.png)