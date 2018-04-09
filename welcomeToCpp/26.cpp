  #include <iostream>

  /*
  Every time we enter a scope in C++ we basically push stack frame on:

  function scope,
  if scope,
  empty scope,
  class scope
  */

  #define Log(x) std::cout << x << std::endl;
  #define fillPointerArray(pointerArray, count) for (int i = 0; i < count; i++) *(pointerArray + i) = i;
  #define showPointerArray(pointerArray, count) for (int i = 0; i < count; i++) Log( *(pointerArray + i) );

  class Entity {
  public:
    int x;

    explicit Entity(int x) : x(x) {
      Log("Creating ...");
      Log(this->x);
    };
    ~Entity() {
      Log("Destroying ...");
      Log(this->x);
    };
  };

  int* my_Function(const int count) {
    int* array = new int[count];
    fillPointerArray(array, count);

    // returning a pointer to heap memory
    return array;

    // stack memory get cleared as soon as we are out of scope
  }

  int returnint() {
    return 2;
  }

  // Declaring a smart pointer for integers
  class scopedPointerInteger {
  private:
    int* pointer;
  public:
    scopedPointerInteger(int* integer) : pointer(integer) {};
    ~scopedPointerInteger() { delete pointer; };
  };

  // Declaring a smart pointer for Entity class
  class scopedPointerClass {
  private:
    Entity* entity;
  public:
    scopedPointerClass(Entity* entity) : entity(entity) {};
    ~scopedPointerClass() { delete entity; };
  };

  int main() {

    Log("BEFORE");
    {
      Entity entity(10); // stack
      scopedPointerClass scopedpointerclass = new Entity(200); // it will delete the pointer when we are out of scope
      Entity* entity2 = new Entity(100); // heap
      delete entity2;
    }

    Log("AFTER");


    const int count = 10;
    showPointerArray(my_Function(count), count);

    int* mypointerarray = (int*) my_Function(count);
    showPointerArray(mypointerarray, count);

    delete mypointerarray;
  }
