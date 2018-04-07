  #include <iostream>
  #include <string>

  #define Log(x) std::cout << x << std::endl;

  class Example {
  public:
    Example() {
      Log("created Entity");
    };

    Example(int x) {
      Log("created Entity with");
      Log(x);
    };
  };

  class Entity {
  private:
    std::string m_Name;
    int m_Score;
    Example m_example;
  public:
    std::string test;
  public:
    Entity()
      : m_Name("Unknow"), m_Score(0), m_example(Example(8)) {
        Log("... Constructer is working");
        /*
        m_Name = "Unkown";
        m_Name = std::string("Unkown");
        */

        // losing performance
        // test = "testing";
        test = std::string("testing");
        // therefore it is a bad idea

        m_example = Example(8);
      };

    Entity(const std::string& name, int score)
      : m_Name(name), m_Score(score) {
        Log("... Constructer is working");
      };

    const std::string& getName() {
      return m_Name;
    }
  };

  int main() {
    Entity entity;
    Log( entity.getName() );
    Log( entity.test );

    Entity entity2("mahta", 100);
    Log( entity2.getName() );

    int Speed = 4;

    int speed = (Speed > 4) ? (Speed < 10) ?  100 : 1000 : 10000 ;

    Log(speed);

    std::cin.get();
  }
