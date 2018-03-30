  // anything begins with a hash is known as a preprocessor
  // pragma once means only include this file once
  #pragma once
  // usning a header file you can declare any thing and by including the header
  // file in any cpp file you can use them.

  // we can use #ifndef instead of progma once
  // I personally use progma once
  #ifndef _LOG_f
  #define _LOG_f
  static void LogInit() {
    std::cout << "welcome to header files in c++" << std::endl;
  }

  static void Log(const char* message) {
    std::cout << message << std::endl;
  }

  static void LogNumber(int number) {
    std:: cout << number << std::endl;
  }

  static void LogGoodBye() {
    std::cout << "Goodbye for a while" << std::endl;
  }
  #endif

  struct myStruct {};
