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

    Log("---------------------------------");

    return 0; // the end of the main function
    // dead code: 
    for (int i = 0; i < 10; i++) {
      if ( i % 2 == 0) continue;
      if ( i == 9) continue;
      LogNumber(i);
    }

    std::cin.get();
  }
