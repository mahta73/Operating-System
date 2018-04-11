  #include <iostream>
  // platform-independent
  #include <chrono>  // std::chrono::seconds, std::chrono::milliseconds
                     // std::chrono::duration_cast, ...
  #include <thread>
  #include <unistd.h>
  #include <typeinfo>

  #define Log(x) std::cout << x << std::endl;

  struct Timer {
  public:
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
  public:
    Timer() {std::chrono::duration<float>
      start = std::chrono::high_resolution_clock::now();
    };
    ~Timer() {
      end = std::chrono::high_resolution_clock::now();
       duration = end - start;
       Log(duration.count());
    };
  };

  // NOTE_: thread sleeps are not guaranteed to be exactly how much you tell it to sleep for
  int main(int argc, char* argv[]) {

    // current time
    auto start = std::chrono::high_resolution_clock::now(); // it returns a time pointer
    Log( typeid(start).name() );
    // current thread sleeps for one second
    sleep(1);

    auto end = std::chrono::high_resolution_clock::now();

    // Class template std::chrono::duration represents a time interval.
    std::chrono::duration<float> duration = end - start;
    // Returns the internal count (i.e., the representation value) of the duration object.
    Log(duration.count());
    // instead of this long code we can creat a class or struct timer
    std::cin.get();
  }
