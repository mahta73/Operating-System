  // Creating a thread using Function Objects

  #include <iostream>
  #include <thread>
  
  using namespace std;

  class my_class {
  public:
    void operator()() {
      for (int i = 0; i < 50; i++) {
        cout << "THREAD" << endl;
      }
    }
  };

  int main() {
    my_class my_thread_function;
    thread my_thread(my_thread_function);

    for (int i = 0; i < 50; i++) {
      cout << "MAIN" << endl;
    }

    cout << "waiting for thread to complete" << endl;

    my_thread.join();

    cout << "main exit" << endl;
    return 0;
  }
