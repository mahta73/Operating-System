  // iostream is the header file which contains all the functions of program like cout, cin etc.
  // #include tells the preprocessor to include these header file in the program.
  #include <iostream>
  // the functions and classes for managing threads are declared in <thread>.
  #include <thread>
  using namespace std;

  // Every thread has to have an initial function, which is where the new thread of execution begins.
  void hello() {
    std::cout << "Hello Concurrent worl \n";
  }

  // first thread in an application is main()
  int main() {
    // threads are specified in the constructor of a std :: thread
    // The initial thread that starts at main() and the new thread that starts at hello()
    std::thread t(hello);
    // join() causes the calling thread to wait for the thread asociated with the std :: thread object
    t.join();
    return 0;
  }

  // g++ -std=c++11 -pthread learnCPP.cpp
