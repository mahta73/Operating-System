  // virtual, override

  /*
    Virtual Function (dynamic dispatch)
    V-table is basically table which contains a mapping for all
    the virtual functions inside our base class therefore we can
    actually map them to the correct overwritten function at runtime
  */
  #include <iostream>
  #include <string>

  #define Log(x) std::cout << x << std::endl;

  // Interface is a class with pure virtual functions
  class Interface {
  public:
    virtual std::string getClassName() = 0;
  };

  class Entity : public Interface {
  public:
    // hey generate a V table for this function so that if it's
    // overwritten you can point to the correct function
    virtual std::string GetName() {
      return "Entity";
    };

    std::string getClassName() override {
      return "Entity";
    };
  };

  class Player : public Entity {
  private:
    std::string m_Name;
  public:
    Player(const std::string& name) : m_Name(name) {}

    // in c++11 you can actually mark this overwritten function
    // with the keyword override
    std::string GetName() override {
      return m_Name;
    };

    std::string getClassName() override {
      return "Player";
    };
  };

  // type is Entity pointer , (it checks Entity class)
  void PrintName(Entity* entity) {
    std::cout << entity->GetName() << std::endl;
  }

  void PrintClassName(Interface* interface) {
    std::cout << interface->getClassName() << std::endl;
  }

  int main() {
    Entity* entity = new Entity();
    std::cout << entity->GetName() << std::endl;
    PrintName(entity);
    Log("class Name:");
    PrintClassName(entity);

    Player* player = new Player("Cherno");
    std::cout << player->GetName() << std::endl;
    PrintName(player);
    Log("class Name:");
    PrintClassName(player);

    Entity* entity_p = player;
    std::cout << entity_p->GetName() << std::endl;
    PrintName(entity_p);
    Log("class Name:");
    PrintClassName(entity_p);

    Player player_np("mahta");
    std::cout << player_np.GetName() << std::endl;

    delete entity;
    delete player;
    delete entity_p;
    std::cin.get();
  }
