  /*
    #include <thread> -> The compiler can see the definition of thread class
    void do_some_work();
    std::thread my_thread(do_some_work);
  */

  // POINT_1: std :: thread works with any callable type, so you can pass an instance
  // of a class with a function call operator to the std :: thread constructor instead.

  #include <iostream>
  #include <thread>

  class background_task {
  public:
    void operator()() const {
      do_something();
      do_something_else();
    }
  };

  int main() {
    background_task f;
    std :: thread my_thread(f);
    my_thread.join();
    return 0;
  }
