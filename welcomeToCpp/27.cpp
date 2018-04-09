  /*
  unique pointer is a scoped pointer meaning that when that pointer
  goes out of scope it will get destroyed and it will call delete.
  unique pointers have to be unique, you can't copy a unique pointer
  because if you copy a unique pointer the memory that it's pointing to
  they'll basically have two pointers two unique pointers pointing to the
  same block of memory and when one of them dies it will free that memory
  meaning that suddenly that second unique pointer you had pointed to the
  same block of memory is pointing to memory that's been freed so you cannot
  copy unique pointers
  */
  #include <iostream>
  // The first thing you'll need to get to access to all these smart pointers is:
  #include <memory>

  #define Log(x) std::cout << x << std::endl;

  class Entity {
  public:
    explicit Entity() {
      Log("Created Entity");
    };

    ~Entity() {
      Log("Destroyed Entity");
    };

    void Print() {
      Log("Some function");
    }
  };

  int main() {
    {
      // unique_ptr is explicit
      std::unique_ptr<Entity> entity = std::make_unique<Entity>();
      entity->Print();
    }
  }
