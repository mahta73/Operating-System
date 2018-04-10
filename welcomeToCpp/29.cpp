  #include <iostream>

  #define Log(x) std::cout << x << std::endl;

  class Vector2 {
  public:
    float x, y;
  public:
    explicit Vector2(float x, float y) : x(x), y(y) {};
  };

  int main() {
    int a = 2;
    int b;
    b = a; // in c++ a and b are two different variables which have
    // different memory addresses
    Vector2 vector2(0.2f, 26.5f);
    Log(vector2.x);

    // vector2 and vector3 are independent of each other
    Vector2 vector3 = vector2;
    vector3.x = 50;
    Log(vector3.x);

    // however with pointers?
    Vector2* c = new Vector2(2.0f, 3.0f);
    Vector2* d = c;

    d->x = 103000000.5f;

    Log(c->x);
  }
