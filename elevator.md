***Disk Scheduling Algorithm***

Seek Time is measured defines the amount of time it takes a hard drive's
read/write head to find the physical location of a piece of data on the disk.  

When anything is read or written to a disc drive, the read/write head of the disc
needs to move to the right position. The actual physical positioning of the
read/write head of the disc is called seeking. The amount of time that it
takes the read/write head of the disc to move from on part of the disk to
another is called the seek time. The seek time can differ for a given disc due
to the varying distance from the start point to where the read/write head has
been instructed to go. Because of these variables, seek time is generally
measured as an average seek time.  

In operating systems, seek time is very important. Since all device requests
are linked in queues, the seek time is increased causing the system to slow down.

```
The less the head has to move the faster the seek time will be.  
```
Disk Scheduling Algorithms are used to reduce the total seek time of any request.  

***Some types of disk scheduling algorithms***

1. FCFS (First Come-First Serve)

The first come, first served (commonly called FIFO ‒ first in, first out) process
scheduling algorithm is the simplest process scheduling algorithm.    
It is rarely used in modern operating systems, but is sometimes used inside of
other scheduling systems.    
The first process to arrive (First In) is the first one to be dealt with (First Out).

Advantages:    
  1. simple  
  2. easy    
  3. first come, first served      
Disadvantages:    
  1. This scheduling method is nonpreemptive, that is, the process will run until it finishes.    
  2. Because of this nonpreemptive scheduling, short processes which are at the back
  of the queue have to wait for the long process at the front to finish.  

```
PSUDOCODE:

queueType queue; // declare a queue

while( queuse is not empty) {
  // take the last element of the queue
}
```

2. SSTF (Shortest Seek Time First)  

This is a direct improvement upon a first-come first-served (FCFS) algorithm.    
In SSTF (Shortest Seek Time First), requests having shortest seek time are executed first.    
Minimal seek time is the criteria for selection of requests.  

Advantages:  
  1. It is substantial improvement over FCFS.  
  2. It is essential from of shortest job first scheduling.  
Disadvantages:  
  1. It may cause starvation of some requests
  2. It is not optimal

```
PSUDOCODE:

queueType queue = fill it with some random numbers; // declare a queue of a certain size
Type Head = somewhere between zero and size;

for_each_element_in_queue() {
  // compute the distance between head and queue element
  // find the shortest distance
  // set the Head to that element
  // take out the element
}
```

3. SCAN (Elevator)  
4. C-SCAN (Circular SCAN)  
5. LOOK  
6. C-LOOK  

```
The most important is to make sure every order is followed, that there is no starvation.
```
