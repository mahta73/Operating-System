  // At the end of the day, operators are just functions
  #include <iostream>

  #define Log(x) std::cout << x << std::endl;

  struct Vector2 {
    float x, y;

    explicit Vector2(float x, float y)
    : x(x), y(y) {};

    Vector2 operator+ (const Vector2& vector2) const {
      return Vector2(x + vector2.x, y + vector2.y);
    };

    bool operator== (const Vector2& vector2) const {
      return x == vector2.x && y == vector2.y;
    };
  };

  std::ostream& operator<< (std::ostream& stream, const Vector2& vector2) {
    stream << vector2.x << ", " << vector2.y;
    return stream;
  };

  int main() {

    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);

    Vector2 result = position + speed;
    Log(result.x);
    Log(result.y);

    Log(result);

  }
