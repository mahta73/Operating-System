  #include <iostream>
  #include <thread>
  #include <mutex>
  #include <unistd.h>
  #include <condition_variable>

  static std::mutex mtx;
  static std::deque<int> q;
  static std::condition_variable convar;

  void function_1() {
    int count = 10;

    while (count > 0) {
      // for access of queue
      std::unique_lock<mutex> locker(mtx);
      q.push_front(count);
      locker.unlock();
      sleep(1);
      count--;
    }
  }

  void function_2() {
    int data = 0;

    while (data != 1) {
      // for access of queue
      std::unique_lock<mutex> locker(mtx);

      if( !q.empty()) {
        data = q.back();
        q.pop_back();
        locker.unique_lock();
        std::cout << "t2 got a value from t1" << data << endl;
      } else {
        locker.unlock();
      }
    }
  }

  int main() {

  }
