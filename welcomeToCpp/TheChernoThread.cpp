  #include <iostream>
  #include <thread>
  #include <unistd.h>

  typedef unsigned int uint;

  #define conLog(x) std::cout << x << std::endl; sleep(3);

  static bool s_isFinished = false;

  // print a message
  void  Log(const std::string& message) {
    std::cout << message << std::endl;
  };

  // Print a message n times
  void PrintSeveralTimes(int n,const std::string& message, void(*func)(const std::string&)) {
    for (uint i = 0; i < n; i++) {
      func(message);
      // thread sleeps for a second
      sleep(1);
    }
  };

  // function for a Thread
  void anything() {
    int n = 0;
    auto id = std::this_thread::get_id();

    while(!s_isFinished) {
      conLog(id);
      PrintSeveralTimes(1, "THREAD", Log);
    };
  };

  int main() {
    std::thread my_thread(anything);

    Log("Main thread befor 'ENTER'  ");
    std::cin.get();
    s_isFinished = true;
    Log("Main thread after 'ENTER'  ");

    my_thread.join();
    Log("Thread is finished");

    std::cin.get();
  }
