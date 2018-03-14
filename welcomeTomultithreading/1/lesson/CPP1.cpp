  /*
  In every C++ application there is one default main thread i.e. main() function.
  in C++ 11 we can create additional threads by creating objects of std::thread class.
  Each of the std::thread object can be associated with a thread.

  Header Required : <thread>

  What this std::thread object will execute ?

  We can attach a callback with the std::thread object, that will be executed when
  this new thread starts. These callbacks can be,

  1.) Function Pointer
  2.) Function Objects
  3.) Lambda functions

  Thread objects can be created like this,

  std::thread thObj(<CALLBACK>);

  New Thread will start just after the creation of new object and will execute
  the passed callback in parallel to thread that has started it.
  Moreover, any thread can wait for another to exit by calling join() function on
  that thread’s object.
  */

  // iostream is the header file which contains all the functions of program like cout, cin etc.
  // #include tells the preprocessor to include these header file in the program.
  #include <iostream>
  // the functions and classes for managing threads are declared in <thread>.
  #include <thread>
  
  using namespace std;

  // Every thread has to have an initial function, which is where the new thread of execution begins.
  void thread_function() {
    std::cout << "Hello Concurrent world \n";
  }

  // first thread in an application is main()
  int main() {
    // threads are specified in the constructor of a std :: thread
    // The initial thread that starts at main() and the new thread that starts at hello()
    std::thread t(thread_function);
    // join() causes the calling thread to wait for the thread asociated with the std :: thread object
    // to finish.
    t.join();
    return 0;
  }

  // g++ -std=c++11 -pthread learnCPP.cpp
