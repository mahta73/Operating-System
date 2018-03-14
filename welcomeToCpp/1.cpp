  // any thing begins with # is a preprocessor statement
  // the first thing a compiler does when it receives a source file
  // is it pre preprocesses all of your preprocessor statements
  // include will find a file (in this case iostream) take all of the contents of that file
  // and just paste it into this current file (header files)
  // why iostream? for example need declaration for a function named cout

  #include <iostream> // this is called preprocessor statement

  // the main function is called the entry point
  // the return type of the main is actually int however we are not returning an integer
  // because main function is especial and you don't have to return any value from the main
  // function, if you don't return anything it will assume you are returning zero

  int main() {
    // << is an overloaded operator so you need to think of them as functions (operators are just functions)
    // cout -> prints to the console
    std::cout << "hello world" << std::endl;
    // our program execution will pause on this line until we press enter
    std::cin.get();
    // we are actually return 0 now -> our program executed successfully
  }

  // How to we get from this text to an actual executable binary file?

  // preprocessor statement evaluated before we compile the file
  // in this case it include all of the content of the iostream file into this file (copy and paste)
  // so we can use cout and cin functions
  // once our preprocessor statement get evaluated our file gets compiled
  // this is the stage where the compiler trasforms our c++ code to the machine code
