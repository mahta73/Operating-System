  // compiling and linking
  // error starts with 'c' for example sintax error are errors at compile stage
  // error starts with 'lnk' for example missing main function are errors at linking stage
  #include <iostream>
  // using std::cout;
  // using std::cin;

  void Log(const char* message) {
    std::cout << message << std::endl;
  };

  // static -> internal linking
  static int multiply(int number1, int number2) {
    Log("... isMultipliying");
    return number1 * number2;
  };

  inline int add(int number1, int number2) {
    Log("... isAdding");
    return number1 + number2;
  }

  // NOTE_: Just know the entry point doesn't have to be the main function,
  //there just has to be an entry point. (but normally is main function)

  int main() {
    std::cout << multiply(10, 5) << std::endl;
    std::cout << add(10, 5) << std::endl;
    std::cin.get();
  }

  /*
  static - the variable/function name cannot be used in other compilation units.
  Linker needs to make sure it doesn't accidentally use a statically defined
  variable/function from another compilation unit.

  extern - use this variable/function name in this compilation unit but don't
  complain if it isn't defined. The linker will sort it out and make sure all the code
  that tried to use some extern symbol has its address.

  inline - this function will be defined in multiple compilation units, don't worry about it.
  The linker needs to make sure all compilation units use a single instance of the
  variable/function.

  Note: Generally, declaring templates inline is pointless, as they have the linkage semantics
  of inline already. However, explicit specialization and instantiation of templates require
  inline to be used.
  */
