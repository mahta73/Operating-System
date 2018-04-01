  #include <iostream>

  #define LOG(x) std::cout << x << std::endl;

  class Entity {
  public:
    float x, y;

    Entity() {
      std::cout << " created " << std::endl;
      x = 0.0f;
      y = 0.0f;
    }

    Entity(int X, int Y) {
      x = X;
      y = Y;
    }

    // Entity() = delete; or you can make constructor private

    ~Entity() {
      std::cout << " destroyed " << std::endl;
    }

  public:
    void Print() {
      std::cout << x << " " << y << std::endl;
    }
  };

  void createObjectOfEntity() {
    Entity entity;
    entity.Print();
  }

  int main() {
    Entity entity;

    // we will get whatever war left over in that memory space
    entity.Print();

    // without constructor
    // cout::std << entity.x << std::endl; -> ERROR: you are trying to utilize
    // memory that has not been initialized
    int result = entity.x;

    LOG(result);

    createObjectOfEntity();

    std::cin.get();
  }
