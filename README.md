Object-Oriented Programming with Animals

Overview:

This C++ program demonstrates polymorphism using a base Animal class with derived Dog, Cat, and Bird classes, showcasing dynamic behavior through virtual functions and unique pointers. It demonstrates fundamental concepts of Object-Oriented Programming (OOP), including:
  - Classes and Inheritance: The Animal class serves as a base class, while Dog and Cat inherit from it.
  - Polymorphism: The do_act function is overridden in derived classes to provide unique behaviors.
  - Virtual Functions: Ensures proper function overriding and dynamic method dispatch.
  - Pointers and Object Slicing: Shows how assigning a derived object to a base class object can strip derived properties.
  - Vectors of Pointers vs. Objects: Illustrates storing polymorphic objects in containers.

Classes and Methods:
  - Animal (Base Class)
    Declares a virtual method do_act() with a default behavior of "Move Move!"
  - Dog (Derived from Animal)
    Overrides do_act() to print "Bark Bark!"
  - Cat (Derived from Animal)
    Introduces an integer member mouse, initialized to 4.
    Overrides do_act() to print "Scratch Scratch!" along with mouse count.

Key Functionalities:
  Main Function (main())
    - Creates instances of Dog, Cat, and Animal.
    - Demonstrates function overriding by calling do_act() on each object.
    - Uses an Animal* pointer to call do_act() on a Cat object, preserving its derived behavior.
    - Assigns a Cat object to an Animal object, demonstrating object slicing.
    - Stores Animal* pointers in a vector<Animal*>, allowing polymorphic behavior.
    - Stores Animal objects in a vector<Animal>, demonstrating object slicing.

Notable Concepts Demonstrated:
- Virtual Functions & Polymorphism
-  Declaring do_act() as virtual allows correct method resolution at runtime.
- Without virtual, calling do_act() through a base class pointer would invoke Animal's implementation.
- Pointers and Object Slicing
- Storing a Cat in an Animal object removes Cat-specific data (mouse count).
- Using an Animal* pointer maintains the correct behavior.
- Vectors and Dynamic Allocation
- vector<Animal*> maintains polymorphic behavior.
- vector<Animal> copies objects, causing object slicing.
- Demonstrates proper memory management (commented-out delete loop).

Compilation & Execution:
- Compile the program using a C++ compiler:
  g++ animals.cpp -o animals
- Run the executable:
  ./animals

Expected Output:
- The dog: Bark Bark!
- The cat: Scratch Scratch! 4
- The snail: Move Move!
- The cat through an Animal Pointer: Scratch Scratch! 4
- The cat assigned to an Animal: Move Move!
- The cat in a vector of Animal: pointers: Scratch Scratch! 4 Bark Bark! Scratch Scratch! 4 Bark Bark!
- The cat in a vector of Animals: Bark Bark! Move Move!

Notes:
The system("pause") at the end is Windows-specific and can be removed for other platforms.
The commented-out delete loop is a reminder for manual memory management when using new.

Improvements:
- Implement a destructor to properly delete dynamically allocated objects.
- Use unique_ptr or shared_ptr for automatic memory management.
- Expand with additional animals demonstrating polymorphism further.

Conclusion:
This program serves as a foundational example of OOP concepts in C++, focusing on class inheritance, function overriding, object slicing, and dynamic polymorphism.


