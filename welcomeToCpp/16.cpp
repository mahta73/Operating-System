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

  class Entity {
  public:
    // hey generate a V table for this function so that if it's
    // overwritten you can point to the correct function
    virtual std::string GetName() {return "Entity";}
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
  };

  // type is Entity pointer , (it checks Entity class)
  void PrintName(Entity* entity) {
    std::cout << entity->GetName() << std::endl;
  }

  int main() {
    Entity* entity = new Entity();
    std::cout << entity->GetName() << std::endl;
    PrintName(entity);

    Player* player = new Player("Cherno");
    std::cout << player->GetName() << std::endl;
    PrintName(player);

    Entity* entity_p = player;
    std::cout << entity_p->GetName() << std::endl;
    PrintName(entity_p);

    Player player_np("mahta");
    std::cout << player_np.GetName() << std::endl;


    delete entity;
    delete player;
    std::cin.get();
  }
