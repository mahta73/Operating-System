  #include <iostream>
  #include "log.h"

  int main() {
    Log("Hello dear hard working");

    for (int i = 10; i < 20; i = i + 1) {
      LogNumber(i);
    }

    Log("\n");

    int i = 10;
    bool condition = true;
    for (; condition; ) {
      LogNumber(i);
      i++;
      if ( !(i < 20) ) condition = false;
    }

    std::cin.get();
  }
