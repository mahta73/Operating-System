  #include <iostream>
  #include <string>
  #include <thread>
  #include <mutex>

  /*
    The condition_variable class is a synchronization primitive that can be used to block a thread,
    or multiple threads at the same time, until another thread both modifies a shared variable
    (the condition), and notifies the condition_variable.
  */

  // lets create a mutexe
  std::mutex mutx;

  // this is a shared recourse -> race condition
  void shared_Log(std::string thread_name, int context) {
    // lock_gaurd
    std::lock_guard<std::mutex> lock(mutx);
    /*
      When a lock_guard object is created, it attempts to take ownership of the mutex it is given.
      When control leaves the scope in which the lock_guard object was created, the lock_guard is
      destructed and the mutex is released.
    */
    // mutx.lock();
    // if this line of code throws expection, our mutex ends up being locked forever
     std::cout << "From: " << thread_name << " " << context << std::endl;
    // mutx.unlock();
  };

  void countDownWard() {
    for (int i = 0; i > -100; i--) {
      shared_Log("Thread", i);
    }
  }

  void countForWard() {
    for (int i = 0; i < 100; i++) {
      shared_Log("Main", i);
    }
  }

  int main() {
    std::thread thread_1(countDownWard);

    countForWard();

    thread_1.join();
  }
