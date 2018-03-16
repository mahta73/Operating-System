  // never write the same code multiple times, never

  #include <iostream>

  int Multiply(int number1, int number2) {
    return number1 * number2;
  }

  void MultiplyAndShow(int number1, int number2) {
    std::cout << Multiply(number1, number2) << std::endl;
  }
  int main() {

    int result = Multiply(2, 3);
    std::cout << result << std::endl;

    int result_2 = Multiply(5, 10);
    std::cout << result_2 << std::endl;

    int result_3 = Multiply(5, 8);
    std::cout << result_3 << std::endl;

    // reapiting code is the worst thing a programmer can do
    // for example you can have array of results, dynamic array is better, (or linked list)
    // fill the array, and print

    MultiplyAndShow(2, 3);
    MultiplyAndShow(5, 10);
    MultiplyAndShow(5, 8);
    // isn't it better? just avoid repeating code as mush as you can
  }
