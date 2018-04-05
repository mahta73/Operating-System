  #include <iostream>
  #include <string>

  using String = std::string;

  class Entity {
  private:
    String m_Name;
  public:
    Entity() : m_Name("Unkown") {}
    Entity( const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
  };

  int main() {
      // 'new' is just an operator, like +, -, ...
      // new returns a pointer to the memory that you allocated
      // single 4 byte integer allocated on the heap
      int* pointer = new int;
      *pointer = 52;

      std::cout << "The value of pointer: " << *pointer << std::endl;

      int* pointer2 = new int[50]; // array, 200 bytes

      Entity* entity = new Entity; // Entity* entity = new Entity()

      Entity* entity2 = new Entity[10];

      /*
        USUALLY calling 'new' will call the underlaying function malloc
        (memory  allocate) malloc(size) and it returns a void pointer
      */

      Entity* entity3 = (Entity*) malloc(sizeof (Entity) );

      /*
      new Entity() -> this will call the constructor
      malloc(sizeof (className) ) -> this will not call the constructor
      */

      // delete is also an operator
      // delete calls c function free()  and also the destructor
      delete pointer;
      delete[] pointer2;
      delete entity;
      delete[] entity2;

      std::cin.get();
  }
