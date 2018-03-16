  // This code is not optmized, just testing how c++ works.:)
  
  // NOTE_: compiler generates object files for each of your c++ files (.obj)
  // .i for preprocessor
  // Once preprocessor stage has done we can move on to actually compiling our c++ code
  // into machine code

  // define preprocessor will do a search for 'INTEGER' and replace it with 'int'
  #define INTEGER int

  #include <iostream>

  using namespace std;

  #if 1
  const char* Log(const char* message) {
    std::cout << message << std::endl;
  };
  #endif

  #if 0
  INTEGER multiply(INTEGER number1, INTEGER number2) {
    return  number1 * number2;
  // compiler opens endBrace and copies its content here
  #include "endBrace.h"
  #endif

  int main() {
    std::cout << Log("hello world") << std::endl;
    std::cin.get();
  }

  /*
  What is constant folding?
    Constant folding is the process of recognizing and evaluating constant
    expressions at compile time rather than computing them at runtime.

    The source code must be compiled into machine code in order to become and
    executable program. ... A compiled program can be opened and run by a user.
    When an application is running, it is called runtime.
    The terms "runtime" and "compile time" are often used by programmers to refer
    to different types of errors
  */
