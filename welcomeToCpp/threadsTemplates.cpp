  #include <iostream>
  #include <string>
  #include <thread>
  #include <unistd.h>
  #include <vector>
  // condition_variable can only be used along with mutex
  #include <mutex>
  #include <chrono>

  static std::mutex mtx;

  #define Log(x) mtx.lock(); std::cout << x << std::endl; mtx.unlock();

  void threadFn(int& value) {
    Log("I am inside a thread function");
    Log(std::this_thread::get_id());
    Log(++value);
  };

  template <typename Type>
  void showType () {
    Log("anyValue");
  };

  void thread_six_function(std::vector<int> lst) {
    Log("Size of list is equal to: ");
    Log(lst.size());
  }

  int main() {
    int value = 23;
    std::thread THREAD (threadFn, std::ref(value));
    std::thread THREAD2 {threadFn, std::ref(value)};
    // [=]() {} -> you can access variables, however you cannot modify it
    std::thread THREAD3([&]() {
      Log("I am inside the third thread");
      Log(++value);
    });

    std::thread THREAD4 (showType<int>);

    sleep(1);

    std::thread THREAD5 (showType<int>);

    std::vector<int> lst = {1, 2, 3, 4, 5};

    std::thread THREAD6 (thread_six_function, lst);

    THREAD.join();
    THREAD2.join();
    THREAD3.join();
    THREAD4.join();
    THREAD5.join();
    THREAD6.join();

    int number = 123456;
    int& number_referect = std::ref(number);
    number = 654321;
    Log(std::ref(number)); // 654321

    Log("the value of 'value' in main thread");
    Log(value);

  }
