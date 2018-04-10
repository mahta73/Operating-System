  #include <iostream>
  #include <string>
  // smart pointers -> when you call 'new' you don't have to call 'delete'
  #include <memory>

  #define Log(x) std::cout << x << std::endl;

  class Entity {
  public:
    int x;

    explicit Entity() : x(100) {
      Log("Created Entity");
    };
    ~Entity() {
      Log("Destroyed Entity");
    };

    virtual void Printer() {
      Log("Inside the printer function");
    };
  };

  class subEntity : public Entity {
    using Entity::Entity;
  public:
    void Printer() override {
      Log("Using virtual functions");
    };
  };

  int main() {
    // unique pointer is a scoped pointer
    // std::unique_ptr<type> name = std::make_unique<type>();

    {
      std::unique_ptr<Entity> entity = std::make_unique<Entity>();
      entity->Printer();

      std::unique_ptr<subEntity> subentity = std::make_unique<subEntity>();
      Log(subentity->x);
    }

    std::shared_ptr<Entity> copyEntity;
    // shared pointer
    {
    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
    copyEntity = sharedEntity;

    // std::weak_ptr will not increase the ref count
    }

    Log(copyEntity->x)
  }
