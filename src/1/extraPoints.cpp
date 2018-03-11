  // Each of the std::thread object has an associated ID and we can fetch using.
  // get_id()
  #include <iostream>
  #include <thread>
  using namespace std;

  void thread_function() {
      cout << "Thread :: ID  = " << this_thread::get_id() << endl;
  }

  int main()
  {
      thread thread1(thread_function);
      thread thread2(thread_function);

      if( thread1.get_id() != thread2.get_id() ) {
          cout << "Threads with different Ids" << endl;
      }

      cout << "From Main Thread :: ID of Thread 1 = " << thread1.get_id() << endl;
      cout << "From Main Thread :: ID of Thread 2 = " << thread2.get_id() << endl;
      cout << "From Main Thread :: ID of Main Thread = " << this_thread::get_id() << endl;

      thread1.join();
      thread2.join();

      return 0;
  }
