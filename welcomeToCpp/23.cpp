  #include <iostream>
  #include <string>

  using std::string;
  using std::cout;
  using std::endl;

  #define Log(x) cout << x << endl;

  class Entity {
  private:
    string m_Name;
    int m_Age;
    
  public:
    Entity(const string& name)
    : m_Name(name), m_Age(-1){};

    Entity(int age)
    : m_Name("Unknown"), m_Age(age){};


    const string& getName() {
      return m_Name;
    };

    int getAge() {
      return m_Age;
    };

  };

  class Entity2 {
  private:
    string m_Message;
  public:
      // explicit means no implicit conversion is allowed
    explicit Entity2()
    : m_Message("IT IS POSSIBLE"){};

    explicit Entity2(const string& message)
    : m_Message(message) {};
  };

  void PrintEntity(const Entity& entity) {
   Log("PrintEntity ...");
  }
  int main() {

    // Try to avoid implicit conversions

    PrintEntity(22);

    /*
    PrintEntity("It is possible");
    In order for this to work C++ would actually have to do two conversions
    One from a Const char array into a string and then one from a string
    to an entity.
    IT IS ONLY ALLOWED TO DO ONE IMPILICIT CONVERSION.
    */

    PrintEntity(string("It is possible"));
    PrintEntity(Entity("It is possible"));

    const string my_Name = "Mahta";
    Entity entity = my_Name;
    Log(entity.getName());
    Log(entity.getAge());

    Entity entity2 = 22;
    Log(entity2.getName());
    Log(entity2.getAge());

  }
