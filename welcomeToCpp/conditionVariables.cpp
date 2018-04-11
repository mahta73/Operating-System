  #include <iostream>
  #include <thread>
  #include <chrono>
  #include <unistd.h>
  // condition_variable can only be used along with mutex
  #include <mutex>
  // are used as a signal mechanism between threads
  #include <condition_variable>

  #define Log(x) std::cout << x << std::endl;

  void ThreadFn(std::mutex& mtx, std::condition_variable& convar) {
    std::unique_lock<std::mutex> lock(mtx);
    // we cannot use lock_guard over here, it takes unique_lock
    convar.wait(lock); // waits and mutex mtx is released
    Log("End of thread");
  }

  int main() {
    std::mutex mtx;
    std::condition_variable convar;

    std::thread my_thread_1 {ThreadFn, std::ref(mtx), std::ref(convar)};

    sleep(10);

    {
      std::lock_guard<std::mutex> lg(mtx);
      convar.notify_all();
    }

    my_thread_1.join();
    Log("End of the main function");
  }
