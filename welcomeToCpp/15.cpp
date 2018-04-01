  #include <iostream>

  class Entity {
  public:
    float X, Y;

    void Move(float xa, float ya) {
      X += xa;
      Y +=ya;
    }
  };

  class Player : public Entity {
  public:
    const char* name;

    void Print() {
      std::cout << name << std::endl;
    }
  };

  int main() {

    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;

    Player player;
    player.Print();
    
    std::cin.get();
  }
