  #include <iostream>

  class Entity {
  private:
    std::string m_Name;
    // const method inside the class can modify this variable
    mutable int m_DebugCount = 0;
  public:
    const std::string& getName() const {
      m_DebugCount++;
      return m_Name;
    };
  };

  int main() {
    const Entity e;
    e.getName();

    int x = 8;

    auto f = [=]() mutable {
      x++;
      std::cout << x << std::endl;
    };

    auto f2 = [&]() {
      x++;
      std::cout << x << std::endl;
    };

    f();

    std::cin.get();
  }
