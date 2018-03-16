
  // #include <iostream>
  // NOTE_: iostream is actually a file
  #include "iostream"
  #include "log.h"

  /*
  some include statements use "", some include statements use <>, why?
  "" -> path is on our folder, ("" is relevant to the current file)
  <> -> relative to include directeries
  NOTE_: you can use "" for every thing
  */
  int main() {
    std::cout << "hello world" << std::endl;
    Log("hello world");
    std::cin.get();
  }
