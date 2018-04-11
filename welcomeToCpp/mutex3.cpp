  #include <iostream>
  #include <thread>
  #include <mutex>
  #include <unistd.h>

  #define Log(x) std::cout << x << std::endl;

  void ThreadFn(std::mutex& mtx) { // 3.1
    std::lock_guard<std::mutex> lock(mtx);
    Log("I Locked the mutex");
    sleep(5);
  }

  int main() {
    std::mutex mtx; // 1
    std::thread my_thread {ThreadFn, std::ref(mtx)}; // 2

    sleep(1); // 3.2

    std::lock_guard<std::mutex> lock(mtx); // 4
    Log("I am inside the main thread"); // 5

    /*
      std::unique_lock<mutex> lock(mtx);
      lock.lock;
      lock.unlock();
    */

    my_thread.join();
  }
