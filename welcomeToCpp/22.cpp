    #include <iostream>
    #include <string>

    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;

    #define Log(x) cout << x << endl;

    class Entity {
    private:
      string m_Name;
    public:
      // defult constructor
      Entity() : m_Name("Unknown") {};
      Entity(const string& name) : m_Name(name) {};

      const string& getName() const {
        return m_Name;
      };
    };

    void Function() {
      // when the funtion ends that stack frame gets destroyed
    };

    int main() {
      // on heap
      const Entity* e;
      // on stack, the fastest way and the most managed way, stack is usaully small
      {
      const Entity entity("mahta"); // const Entity entity = Entity("mahta");
      e = &entity;
      Log( entity.getName() );
      Log( (*e).getName() );
      Log( e->getName() ); 
      }

      cin.get();
    }
