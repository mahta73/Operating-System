  /*
    #include <thread> -> The compiler can see the definition of thread class
    void do_some_work();
    std::thread my_thread(do_some_work);
  */

  // POINT_1: std :: thread works with any callable type, so you can pass an instance
  // of a class with a function call operator to the std :: thread constructor instead.

  #include <iostream>
  #include <thread>
  // The header <algorithm> defines a collection of functions especially designed
  // to be used on ranges of elements (std :: for_each)
  #include <algorithm>
  // Vectors are sequence containers representing arrays that can change in size.
  #include <vector>

  using namespace std;

  class WorkerThread
  {
  public:
      void operator()()
      {
          cout << this_thread::get_id() << " ... isExecuting" << endl;
      }
  };
  int main()
  {
      vector<thread> threadList;

      for(int i = 0; i < 10; i++)
      {
          threadList.push_back( thread( WorkerThread() ) );
      }
      // Applies function mem_fn to each of the elements in the range [threadList.begin(),threadList.end()).
      for_each(threadList.begin(),threadList.end(), mem_fn(&std::thread::join));

      cout << "Exiting from Main Thread" << endl;
      return 0;
  }
