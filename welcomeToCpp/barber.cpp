  #include <iostream>
  #include <thread>
  #include <mutex>

  class semaphore {
  public:
    int count;
    // how to initialize the count of queue from constructor
    int queue[10];
    int index;

  public:
    semaphore(const int count) {
      index = 0;
      this.count = count;
    };

    void s_wait() {
      count--;
      if (count < 0) {
        if (index < 10) {
          queue[index] = // the process;
          index++;
        }
      }
    };

    void s_signal() {
      count ++;
      if (count <= 0) {
        // take out from queue
        index--;
      }
    };
  };

  int numberOfFreeWRSeats = 4;
  int main() {

  }

  /*
  # The first two are mutexes (only 0 or 1 possible)
  Semaphore barberReady = 0
  Semaphore accessWRSeats = 1     # if 1, the number of seats in the waiting room can be incremented or decremented
  Semaphore custReady = 0         # the number of customers currently in the waiting room, ready to be served
  int numberOfFreeWRSeats = N     # total number of seats in the waiting room

  def Barber():
    while true:                   # Run in an infinite loop.
      wait(custReady)             # Try to acquire a customer - if none is available, go to sleep.
      wait(accessWRSeats)         # Awake - try to get access to modify # of available seats, otherwise sleep.
      numberOfFreeWRSeats += 1    # One waiting room chair becomes free.
      signal(barberReady)         # I am ready to cut.
      signal(accessWRSeats)       # Don't need the lock on the chairs anymore.
      # (Cut hair here.)

  def Customer():
      wait(accessWRSeats)         # Try to get access to the waiting room chairs.
      if numberOfFreeWRSeats > 0: # If there are any free seats:
        numberOfFreeWRSeats -= 1  #   sit down in a chair
        signal(custReady)         #   notify the barber, who's waiting until there is a customer
        signal(accessWRSeats)     #   don't need to lock the chairs anymore
        wait(barberReady)         #   wait until the barber is ready
        # (Have hair cut here.)
      else:                       # otherwise, there are no free seats; tough luck --
        signal(accessWRSeats)     #   but don't forget to release the lock on the seats!
        # (Leave without a haircut.)
  */
