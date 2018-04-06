  #include <iostream>
  // c++11 standard array
  #include <array>

  #define Log(x) std::cout << x << std::endl;
  #define forLoop(pointer) { for (unsigned int i = 0; i < size; i++) { int result = *(pointer + i); Log(result); } }
  #define showArray(array, size) for (unsigned int i = 0; i < size; i++) Log(array[i])
  #define fillArray(array, size) for (unsigned int i = 0; i < size; i++) array[i] = i

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

    // arrays in c++ are just pointers
    const int size = 5;
    int my_array[size];

    fillArray(my_array, size);
    showArray(my_array, size);

    int* my_array_p = my_array;
    forLoop(my_array_p);

    // on stack
    int stack_array[10];

    int countOfArray = sizeof(stack_array) / sizeof(int);

    Log(sizeof(stack_array));
    Log("count of array is");
    Log(countOfArray);

    // on heap
    int* heap_array = new int[10];
    delete[] heap_array;

    // c++ standard array
    std::array<int, 10> cpp11_array;
    fillArray(cpp11_array, cpp11_array.size());
    showArray(cpp11_array, cpp11_array.size());

    std::cin.get();
  }
