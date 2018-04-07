  // POINT: const char*
  // string literal only on read only section of memory
  // string is stored in the const section
  #include <iostream>
  #include <string>
  #include <stdlib.h>

  #define String std::string
  #define Cout std::cout
  #define Endl std::endl
  #define Log(x) Cout << x << Endl

  const char* returnString() {
    return "this function is returning a string";
  }

  // string copying is actually quite slow
  // whenever you pass a string make sure you pass it as const &
  void showString(const std::string& string) {
    Log(string);
  }

  class Entity {
  public:
    int getX() const { // this only works in a class by the way
      m_y = 10;
      return m_x;
    }

    const int* const getXpointer() const {
      return m_px;
    }

    void setX(int x) {
      m_x = x;
    }

  private:
    // mutable in c++ means it can be changed
    // we can modify mutable variables even in const methods
    mutable int m_y;
    int m_x;
    const int *m_px, *m_py;
  };

  // you cannot modify Entity because of const
  void PrintEntity(const Entity& e) {
    Log(e.getX()); // if getX was not a constant, it would be an error
  }

  int main() {
    // char is byte of memory
    // utf-16 -> 16-bit character coding (2^16)

    // this is not heap allocated
    // if you don't use the 'new' keyword don't use 'delete' keyword
    const char* name = "mahta";
    /*
      The null termination character:
      that is how we know where the string ends
    */
    Log(name);

    const char name2[6] = {'m', 'a', 'h', 't', 'a', 0 };
    Log(name2);

    const char* result = returnString();
    Log(result);

    String message = "work for your dreams";
    Log(message);

    const char* message2 = "don't hesitate, It will get late so soon";

    String message2_copy = message2;

    Log(message2_copy);

    Log(message2);

    showString("const char*, const std::string& ");

    // wide character
    const char* one = u8"const char*";
    const wchar_t* two = L"const wchar_t*";
    const char16_t* three = u"const char16_t*";
    const char32_t* four = U"const char32_t*";

    const char* example =
    R"(my
    name
    is
    mahta)";

    Log(example);

    // const keyword in c++

    const int MAX_AGE = 90;

    // ceate integer on heap
    int *a = new int;
    *a = 2;
    a = (int*) &MAX_AGE;
    Log(a);
    Log(*a);

    // you cannot modify the contents of that pointer
    // however, you can reassign the actual pointer
    // const int* = int const*
    const int* b = new int(25);
    b = (int*) &MAX_AGE;
    Log(b);
    Log(*b);

    // you can change the contents of the pointer
    // however you cannot reassign the actual pointer
    int* const c = new int;
    *c = 15;

    Log(c);
    Log(*c);

    // You can write the 'const' twice

    const int* const d = new int(15);

    Log(d);
    Log(*d);

    Entity entity;
    entity.setX(10000);
    PrintEntity(entity);

    std::cin.get();
  }
