  #include <iostream>

  #define LOG(x) std::cout << x << std::endl;

  // classes are types which basically create a new varible type
  class Player {
    // by default class variables are private
  public: // visibility
    int x, y;
    int speed;

    void move(int x,int y) {
      this->x += x * speed;
      this->y += y * speed;
    }
  }; // we do need a semicolon

  int main() {

    // we write the type and then we give it any name, like othe c++ variables
    Player player;
    player.x = 5;
    player.y = 6;
    player.move(4, 5);

    LOG(player.x);
    LOG(player.y);

    std::cin.get();
  }
