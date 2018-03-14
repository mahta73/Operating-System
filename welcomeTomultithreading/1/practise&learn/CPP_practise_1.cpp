  // Creating a thread using Function Pointer

  #include <iostream>
  #include <thread>
  
  using namespace std;

  void initial_function() {
    for (int i = 0; i < 50; i++) {
      cout << "THREAD" << endl;
    }
  }

  int main() {
    thread my_thread(initial_function);

    for (int i = 0; i < 50; i++) {
      cout << "MAIN" << endl;
    }

    my_thread.join();

    cout << "exit of main function" << endl;
    return 0;
  }
