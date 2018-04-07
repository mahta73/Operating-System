  // cin is an object of class istream and cout is an object of class ostream
  #include <iostream>
  #include <string>
  #include <functional>
  #include <fstream>
  /*
  ofstream -> write
  ifstream -> read
  fstream -> read and write
  */
  #include <thread>
  #include <mutex>

  // trying to protect the shared resource 'std::cout'
  // shared resource
  class LogFile {
    // initialize a mutex
    std::mutex m_mutex;
    // ofstream class to write on files
    std::ofstream my_ofstream;
  public:
    LogFile() {
      // open a file
      my_ofstream.open("log.txt");
    }; // need destructor to colse file
    ~LogFile() {
      /*
      When we are finished with our input and output operations on a file we shall
      close it so that the operating system is notified and its resources become
      available again.
      */
      my_ofstream.close();
    };

    std::function<void()> shared_print(std::string id, int value) {
      std::lock_guard<std::mutex> locker(m_mutex);
      my_ofstream << "From " << id << ": " << value << std::endl;
    };
  };


  int main() {> lock(mutx);> lock(mutx);
    LogFile logfile;
    std::thread myThread();
  }
