   // barber is a process and customer is another process
  // customer process needs service from barber process

  // initially barber is sleeping
  semaphore barberReady = 0; // first time barber is free

  // initially there is no costumer
  semaphore customerReady = 0; // the singel chair
  semaphore accessWRseats = 1; // first time room is free, is a queue

  // initially n seats are available
  int numberOfSeatsWR = n; // first time room is empty -> resource??

// deadlock free solution
  barber:
    while (true) {
      wait( customerReady ); // c --, if c is less than zero it waits .........., if not continue
        wait( accessWRseats ); // c--, if c is less than zero it waits ........., if not continue
        numberOfSeatsWR ++;
        signal( barberReady );
        signal ( accessWRseats );
          // cut the hair

    }http://www.dreamincode.net/forums/topic/47521-barber-shop-problem/
    customer:
    wait ( accessWRseats );
     if ( numberOfSeatsWR > 0) {
       numberOfSeatsWR --;
     signal ( customerReady );
     signal ( accessWRseats );
     wait ( barberReady );
   } else
   signal ( accessWRseats );
// starvation -> which customer will pick (randomly -> so starvation)
// solution -> using queue
  int main() {
    custormer, barber
  }
