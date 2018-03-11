  // Creating a thread using Lambda functions

  #include <iostream>
  #include <thread>
  using namespace std;

  int main() {
    thread my_thread([]{
      for (int i = 0; i < 50; i++) {
        cout << "THREAD" << endl;
      }
    });

    for (int i = 0; i < 50; i++) {
      cout << "MAIN" << endl;
    }

    my_thread.join();
    return 0;
  }
