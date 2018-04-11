  #include <iostream>
  #include <thread>
  #include <mutex>

  typedef unsigned int uint;

  static bool s_Finished = false;
  std::mutex mymutex; // or std::lock_guard

  #define Log(x) std::cout << x << std::endl;

  void Logxtimes(std::string message) {
    for (uint i = 0; i < 10; i++) {
    mymutex.lock();
    Log(message);
    mymutex.unlock();
    }
  };

  void doWork() {
    using namespace std::Literals::chrono_Literals;

    // if you continually do things as fast as posible like this
    // it is going to kind of result in like a hundred percent CPU
    // usage for that thread which isn't great
    while(!s_Finished) {
      Logxtimes("Main Thread");
      std::this_thread::sleep_for(1s);
    };
  };

  int main() {
    // as soon as we write this actual code it going to immediately
    // kick off that thread
    std::thread worker(doWork); // it takes function pointers

    Logxtimes("Before Main Thread");

    // the way that we can actually wait for something to finish
    // or waint for a thread to complete its work is by:
    std::cin.get();
    s_Finished = true;

    worker.join();
    // on the main thread wait for the worker thread to finish all of
    // its execution before we continue on was with whatever our main thread has

    Logxtimes("After Main Thread");
  }
