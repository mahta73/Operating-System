  #include <iostream>
  #include <string>

  #define Log(x) std::cout << x << std::endl;

  class Entity {
  public:
    std::string GetName() {return "Entity";}
  };

  class Player : public Entity {
  private:
    std::string m_Name;
  public:
    Player(const std::string& name) : m_Name(name) {}

    std::string GetName() {
      return m_Name;
    };
  };

  int main() {
    Entity* entity = new Entity();
    std::cout << entity->GetName() << std::endl;

    Player* player = new Player("Cherno");
    std::cout << player->GetName() << std::endl;

    delete entity;
    delete player;
    std::cin.get();
  }
