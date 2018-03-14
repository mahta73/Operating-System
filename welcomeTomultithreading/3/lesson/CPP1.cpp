  // Pass arguments to threads

  #include <iostream>
  #include <thread>
  #include <algorithm>
  #include <vector>

  using namespace std;

  void thread_function(int x, string s) {
    cout << "THREAD ID: "<< this_thread::get_id() << " " << x << " " << s << " are passed successfully" << endl;
  };

  int main() {
    int myNumber;
    cout << "PLeas enter a number: " << endl;
    cin >> myNumber;

    string myString;
    cout << "Please enter a string" << endl;
    cin >> myString;

    vector<thread> threadList;

    for (int i = 0; i < 10; i++) {
      threadList.push_back( thread( thread_function, myNumber, myString ) );
    }

    for_each(threadList.begin(), threadList.end(), mem_fn(&std::thread::join) );


    cout << "main thread is exiting" << endl;
    return 0;
  }
