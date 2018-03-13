  // Detaching threads
  // Detached threads are also called daemon / Background threads.
  // calling detach() makes the std::thread object not linked with any thread function.
  // NOTE_: before calling join() or detach() we should check if thread is join-able every time
  // NOTE_: Never forget to call either join or detach on a std::thread object with associated executing thread

  #include <iostream>
  #include <thread>

  using namespace std;

  void thread_function() {
    cout << this_thread::get_id() << "... isExecuting" << endl;
  };

  int main() {
    thread thread_1(thread_function);
    thread thread_2(thread_function);

    if ( thread_1.joinable() ) {
      cout << "joinable thread :)" << endl;
      thread_1.join();
    }

    if (thread_2.joinable() ) {
      cout << "joinable thread :)" << endl;
      thread_2.join();
    }

    return 0;
  }
