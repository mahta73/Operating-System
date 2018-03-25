  #ifndef _BARBER_H_
  #define _BARBER_H_
  // the header file for the pthread library
  #include <pthread.h>
  // the STL library: queue
  #include <queue>
  #include <map>
  #include <iostream>

  using namespace std;

  #define DEFAULT_CHAIRS 3 // the default number of chairs for waiting = 3
  #define DEFAULT_BARBERS 1 // the default number of barbers = 1

  class Shop {
  public:
      // constructor
      Shop( int nBarbers, int nChairs );
      Shop( );

      // return a non-negative number only when a customer got a service
      int visitShop( int customerId );

      void leaveShop( int customerId, int barberId );
      void helloCustomer( int barberId );

      void byeCustomer( int barberId );
      // the number of customers dropped off
      int nDropsOff = 0;

  private:
      int nBarbers;
      int nChairs;

      enum customerState {WAIT, CHAIR, LEAVING};

      struct Barber {

          int id;
          pthread_cond_t barberCond;
          int myCustomer = -1; //no customer by default
      };

      struct Customer {
          int id;
          pthread_cond_t customerCond;
          customerState state = WAIT; //waiting state by default
          int myBarber = -1; //no barber by default
      };


      Barber *barbers; //array of barber objects
      map<int, Customer> customers; //container for customer objects


      queue<int> waitingCustomers;
      queue<int> sleepingBarbers;

      pthread_mutex_t mutex1;

      Barber* getBarber(int barberId);
  };

  #endif
