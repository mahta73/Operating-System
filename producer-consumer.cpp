
  // Before the buffer be locked by the consumer, the consumer must be sure that
  // the buffer is not empty
  int n = 0; // global variable, so it is shared, number of items in buffer
  semaphore buffer = 1;

  void producer() {
    produce the item, item

    wait(buffer);
    buffer[n] = item;
    n++;
    signal(buffer);
  }

  void consumer() {

  }

  int main() {
    parbegin(producer, consumer);
  }
