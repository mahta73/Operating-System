  #include <iostream>
  // another name of method is member function
  // inside a member function we can refer to 'this'

  // 'this' IS A POINTER TO THE CURRENT OBJECT INSTANCE THAT THE METHOD BELONGS TO
  // 'THIS' IS A POINTER *******************************************************

  #define Log(x) std::cout << x << std::endl;

  class Entity {
  public:
    int x, y;

    explicit Entity(int x, int y) {
      // Entity * const entity = this; (what we get in constructor (non-const function))
      // Entity& e = *this
      // see, this is just a POINTER to the CURRENT object that method belongs to
      this->x = x;
      // (*this).x
      this->y = y;
      // (*this).y

      Log(this);
    };

    int getX() const {
      // const Entity* const entity = this; (what we get in const methods)
      return x;
    }
  };

  int main() {
    Entity entity(2, 3);
    Log(entity.getX());
    Log(entity.y);
  }
