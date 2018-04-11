  #include <iostream>
  #include <vector>

  #define Log(x) std::cout << x << std::endl;

  typedef float FLOAT32;
  typedef double FLOAT64;
  typedef unsigned int u_int;
  typedef void(*pointerFunction)();
  typedef void(*pointerFunctionWithParameter)(std::string);

  // functions are of course just CPU instructions and they are
  // stored some way in our binary when we actually compile our code
  void HelloWorld() {
    Log("Hello world");
  }
  // when you compile your code every single function gets compiled into
  // CPU instructions and they are somewhere in our binary in our executable
  // file

  void anotherFunction(std::string a) {
    Log(a);
  }

  void PrintValue(int value) {
    Log("Value: ");
    Log(value);
  }

  void forEach(const std::vector<int>& values, void(*func)(int)) {
    for (int value:values) {
      func(value);
    }
  }

  int main() {

    // auto function = HelloWorld(); -> ERROR: HelloWorld returns void
    // HelloWorld -> we are getting the function pointer like &HelloWorld
    // so we are kinda getting the memory address of that function

    // HelloWorld implicit convertion to &HelloWorld
    auto function = HelloWorld;
    function();
    function();
    // void(*)() -> void(*//name)(//parameters) -> this is the actual type of auto in this case
    void(*mahta)() = HelloWorld;
    mahta();

    // typedef - creates an alias that can be used anywhere in place of a type name
    FLOAT32 myFloat = 6.0f;
    Log(myFloat);

    u_int myInt = 5;
    Log(myInt);

    pointerFunction mehrad = HelloWorld;

    mehrad();

    pointerFunctionWithParameter zohreh = anotherFunction;
    zohreh("hello pointer function with parameters");

    std::vector<int> values = {1, 2, 3, 4};
    forEach(values, PrintValue);

    forEach(values, [](int value){
      Log("Value: ");
      Log(value);
    });
  }
