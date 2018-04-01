  // lifetime of the variable refers to how long that actually stick around for
  // in other words how long it will remain in our memory before it gets deleted
  // and scope refers to where we can actually access that variable
  #include <iostream>
  // this variable is only going to be linked internally inside this translation unit.
  // extern
  static int s_variable = 5;

  #define LOG(x) std::cout << x << std::endl;

  enum Example {
    Zero, One, Two
  };

  struct Entity {
    int a = 10;
    static int x, y;

    // static functions can not access non static variables
    // static method does not have a class instance
    static void Print() {
      std::cout << x << ", " << y << std::endl;
    }
  };

  int Entity::x;
  int Entity::y;

  static void Show(Entity e) {
    std::cout << e.x << ", " << e.y << ", " << e.a << std::endl;
  }

  void Increament() {
    static int count = 0;
    count++;
    LOG(count);
  }
  int main() {

    Entity::x = 45;
    Entity::y = 100;

    Entity::Print();

    Entity e;
    Show(e);

    // static local variables allows us to declare a variable that has the lifetime
    // of essentially our entire program however its scope is limited to be inside
    // the function (I am just using function as an example particularly(specifically) I mean any scope)

    Increament();
    Increament();
    Increament();
    Increament();
    Increament();

    Example example = Zero;

    LOG(example);
    std::cin.get();
  }
