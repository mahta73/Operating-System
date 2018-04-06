  #include <iostream>

  #define Log(x) std::cout << x << std::endl;

  int main() {
    int* int_p = new int(123);

    Log(int_p); // address
    Log(*int_p); // value
    Log("**********");

    int* int2_p = new int;
    *int2_p = 321;

    Log(int2_p); // address
    Log(*int2_p); // value
    Log("**********");

    int* int3_p = int2_p;

    Log(int3_p); // address
    Log(*int3_p); // value
    Log("**********");

    std::cin.get();
  }
