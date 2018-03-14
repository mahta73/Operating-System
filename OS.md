
***What is an operating system?***

An operating system is the layer of software that  manages a computer’s resources for its users and their applications.

***Operating systems have three roles:***

* ***Resource sharing: Operating systems play referee.***

1. manage shared resources.

	The operating system must protect itself and other applications from malicious computer viruses. And since the applications are sharing physical resources, the operating system needs to decide which applications get which resources.

2. isolate different applications from each other, so that if there is a bug in one application, it does not corrupt other applications.

***Sharing raises several challenges for an operating system:***

1. Resource Allocation.  
	1. Time Multiplexing: Programs or users take turns i.e. only one at a time.     	Example:Printer.  
	2. Space Multiplexing: Instead of completing one by one, each one get some 	part of the resource.    
	Example:Main Memory  
2. Isolation.  
	An error in one application should not disrupt other applications, or even the 	operating system itself. This is called fault isolation.    
	Fault isolation requires restricting the behavior of applications to less than
	the full power of the underlying hardware.  
3. Communication.  
	The flip side of isolation is the need for communication between different 	applications and between different users. In setting up boundaries, an operating system must also allow for those boundaries to be crossed in carefully controlled ways as the need arises.

* ***Mask hardware limitations: Operating systems play illusionist.***

Operating Systems  provide an abstraction physical hardware to simplify application design.

Operating systems provide the illusion of a nearly infinite memory, as an abstraction on top of a limited amount of physical memory. Likewise, operating systems provide the illusion that each program has the computer’s processors entirely to itself. Obviously,the reality is quite different! These illusions enable applications to be written independently of the amount of physical memory on the system or the physical number of processors. The operating system does so through a concept called virtualization. With the right hardware and operating system support, most physical resources can be virtualized. Even the type of processor can be virtualized.

Some operating systems virtualize the entire computer, to run the operating system as an application running on top of another operating system. This is called creating a virtual machine. The operating system running in the 	virtual machine,called the guest, operating system, thinks it is running on a real,physical machine, but this is an illusion presented by the true operating system running underneath.

Another reason for virtual machines is as an aid in debugging. Moreover, the illusion of atomic updates to data structures is provided by the operating system using some specialized mechanisms providedin hardware.

* ***Common services: Operating systems provide glue.***

Operating system provides a set of common, standard services to applications 	to simplify and regularize their design. An important reason for the operating 	system to provide common services  is to facilitate sharing between	applications.  
Another standard service in most modern operating systems is the graphical
user interface library. This facilitates a common “look and feel” to users, so that 	frequent operations such as pull down menus and “cut” and “paste” are 	handled consistently across applications.

***Operating system design patterns***

A central role of operating systems is protection.

1. Reliability    
	For high system reliability, an operating system must bullet proof itself so that it 	operates correctly regardless of whatever an application or user might do.

2. Security    
	For example, if a malicious application is permitted to write directly to the disk, 	it could modify the file containing the operating system’s code, so that the next 	time the system starts, the modified operating system will boot instead, 	installing spyware and disabling virus protection. For security, an operating 	system must prevent untrusted code from modifying system state.

4. Privacy  
	an operating system must prevent untrusted code from accessing unauthorized data.

5. Efficiency  
	For efficiency and fairness, an operating system must be able to limit the 	amount of resources assigned to each application or user.

***Operating system kernel***

Implementing protection is the job of the operating system kernel. The kernel is the lowest level of software running on the system, with full access to all of the capabilities of the hardware. The operating system kernel runs directly on the processor with unlimited rights.

Applications need to run on the processor with all potentially dangerous operations disabled.  

The kernel is necessarily trusted to do anything that can be done with the hardware. Everything else — that is, the untrusted software running on the system — is run in a restricted environment, with less than complete access to the full power of the hardware.

```
NOTE:  
In turn, applications themselves often need to safely execute untrusted third party  
code. An example is a web browser executing embedded Javascript to draw a  web page.
Without protection, a script with an embedded virus can take control of the browser,
making the user think they are interacting directly with the web when in  fact their
web passwords are being forwarded to an attacker.    
```

***Process***

The execution of an application program with restricted rights is called a process.
A process’s access to hardware is mediated and checked by the operating system kernel. The difference between a process and a program is that a process is an instance of a program.

A “process” was originally coined to mean what we now call a “thread”.    
A process executes a program, consisting of one or more threads running inside a protection boundary.

***Executable image***

a programmer types up some code in some appropriately high-level language. A compiler converts that code into a sequence of machine instructions, and stores those
instructions into a file, called the executable image of the program.

The compiler also defines any static data the program needs, along with their initial values,
and includes them in the executable image.

To start the program running, the operating system copies the program instructions and data from the executable image into physical memory.

***Process Control Block***

The process control block stores all the information the operating system needs about a particular process: where it is stored in memory, where its executable image is on disk, which user asked it to start executing, what privileges the process has, and so forth.

***Dual-mode operation***

A very simple, safe, and entirely hypothetical approach would be to have the operating system kernel simulate, step by step, every instruction in every user process.    
Instead of the processor directly executing instructions, each instruction in a user program would be fetched, decoded, and executed by a software interpreter.

```
Interpreter (computing) In computer science, an interpreter is a computer program
that directly executes, i.e. performs, instructions written in a programming
or scripting language, without requiring them previously to have been compiled
into a machine language program.
```

Before each instruction is executed, the interpreter could check to see if the process had permission to do the operation. The interpreter could allow all legal operations while halting any application that overstepped its bounds.  

Now suppose we want to speed up our hypothetical simulator. Most instruc-
tions are perfectly safe, such as adding two registers together and storing the
result into a third register. Can we modify the processor in some way to allow
safe instructions to execute directly on the hardware?  

To accomplish this, we can implement the same checks as in our hypothetical
interpreter, but we do so in hardware rather than software. This is called dual-
mode operation.  

Hardware support to differentiate between at least two modes of operations, mode bit added to computer hardware to indicate the current mode.

1. user mode: execution done on behalf of a user (single bit in the processor status register = 0)  
2. kernel mode: execution done on behalf of operating system (single bit in the processor status register = 1)  

In user mode, the processor checks each instruction before executing it to verify that the instruction is permitted to be performed by that process.  
In kernel-mode, the operating system executes with protection checks turned off.

At a minimum, the hardware must support three things:

1. Privileged instructions: All potentially unsafe instructions are prohibited when executing in user-mode.

	Instructions available in kernel-mode, but not in user-mode, are called privileged instructions.

	Process isolation is only possible if there is a way to limit programs running in user-mode from directly changing their privilege level.
	Processes can indirectly change their privilege level by executing a special
	instruction called a system call to transfer control into the kernel at a fixed
	location specified by the operating system. Other than trapping into the operating
	system kernel (that is, in effect, becoming the kernel) at these fixed locations,
	an application process cannot be allowed to change its privilege level.

```
The application cannot be allowed to change the set of memory locations it can access
Another limitation on applications is that they cannot disable processor interrupts.

What happens if an application attempts to access memory it shouldn’t or
attempts to change its privilege level?    
Such actions cause a processor exception.  
Interpreter (computing) In computer science, an interpreter is a computer program
that directly executes, i.e. performs, instructions written in a programming or
scripting language, without requiring them previously to have been compiled into a
machine language program.
```

2. Memory protection: All memory accesses outside of a process’s valid
memory region are prohibited when executing in user-mode.

3. Timer interrupts: Regardless of what the process does, the kernel must have a way to periodically regain control from the current process.


***Memory Protection***

The application needs to be in memory in order to execute, while the operating system needs to be in memory to be able to start the program, as well as to handle any
system calls, interrupts, or exceptions.  

How does the operating system prevent a user program from accessing parts
of physical memory?  

Operating system must provide memory protection. In order to have memory
protection, add two registers that determine the range of legal addresses a program
may access:

base register: holds the smallest legal physical memory address.  

Limit register(bound): contains the size of the range memory outside the defined range is protected.

These registers can only be changed by privileged instructions, that is, by the operating system executing in kernel-mode.  
Every time the processor fetches an instruction, the address of the program
counter is checked to see if it lies between the base and the bound registers.
If it doesn't lie between the base and bound registers, the hardware raises an
exception, the program is halted, and control is transferred back to the operating
system kernel.  
Likewise, for instructions that read or write data to memory, each memory
reference is also checked against the base and bounds registers.

```
The operating system kernel executes without the base and bounds registers
```

Although the base and bounds mechanism is sufficient for implementing
protection, it is unable to provide some important features:  

1. Expandable heap and stack.  
2. Memory sharing.  
3. Non-relative memory addresses.  
4. Memory fragmentation.  
As processes are loaded and removed from memory, the free memory space is broken into little pieces. It happens after sometimes that processes cannot be allocated to memory blocks considering their small size and memory blocks remains unused.  

For these reasons, most modern processors introduce a level of indirection,
called virtual addresses, and this comes from the general idea that any problem in computer science can be solved by adding indirection.

without virtual memory we don't have indirection.

```
Program Address = RAM Addreess

An address space is a range of valid addresses in memory that are available for a program or
process.
```

with this direct mapping we are going to crash if we try to access more memory.

Virtual memory takes program addresses and maps them to RAM addresses.

```
Program Address Maps to RAM Address
```

If we try to access more memory, our program is not going to crash. It's going to know it has to get the data from hard disk.

virtual memory gives us flexibility in how we use the RAM.

***virtual Memory Solves Some Problems***
1. Not enough memory: When we need it, we bring in into memory.

```
READING FROM DISK IS SLOWER THAN RAM  
Remember that disks are slower than RAM.  
Any time you can't fit your data in memory and have to go to disk you pay a HUGE performance penalty!  
That is why buying more RAM makes your computer faster.  
```  
2. Holes in the address space: WE can map a program's addresses to RAM addresses however we like.

3. Keeping programs secure: Programs addresses map to different RAM addresses so they can not touch each others data. (Process isolation).  

```
Each program has its own mapping.  
```

4. Share Data: We can use the same mapping to allow programs to share data by simply having their maps point to the same data.  

***Timer interrupts***

Process isolation also requires that the hardware provide a way for the operating system kernel to periodically regain control of the processor.  

Almost all computer systems include a device called a ***hardware timer*** which can be set to interrupt the processor after a specified delay, either in time or timer after some number of instructions have been executed.

Resetting the timer is a privileged operation, accessible only within the kernel, so that the user-level process cannot inadvertently or maliciously disable the timer.

***System Calls***

system calls provide the interface between a running program and the operating system.
Three general methods are used to pass parameters between a running program
and the operating system:  
1. pass parameters in registers.

2. store the parameters in a table in memory, and the table address is passed
as a parameter in a register

3. push (store) the parameters onto the stack by the program, and pop off the stack
by the operating system.


```
LETS CODE :)

int staticVar = 0;
main () {
int localVar = 0;
/* a static variable */
/* a procedure local variable */
staticVar += 1;
localVar += 1;
sleep (10); /* this causes the program to wait for 10 seconds */
printf ( ‘ ‘ static address : %x , value : % d \ n ’ ’ , & staticVar , staticVar );
printf ( ‘ ‘ procedure local address : %x , value : % d \ n ’ ’ , & localVar , localVar );
}
> static address : 5328 , value : 1
> procedure local address : ffffffe2 , value : 1
```

***Safe control transfer***

##### User to kernel mode

There are three reasons for why the kernel will take control from a user
process:  
1. exceptions
2. interrupts
3. system calls.
***What is concurrency?***

At the simplest and most basic level, concurrency is about two or more separate
activities at the same time.  

When we talk about concurrency in terms of computers,we mean a single system performing multiple independent activities in parallel,rather than sequentially, or one after the other.  

Historically, most computers have had one processor, with a single processing unit
or core. Such a machine can really only perform one task at a time, but it can switch
between tasks many times per second. This is called task switching. In order to do the interleaving, the system has to perform a context switch every time it changes from one task to another.We still talk about concurrency (illusion of concurrency) with such systems; because the task switches are so fast.  

Computers with multicore processors are capable of genuinely running more than one task in parallel.We call this hardware concurrency.  

Though the availability in the hardware is most obvious with multiple processor or multicore systems, some processors can execute multiple threads on a single core.  

The number of hardware threads (The measure of how many independent tasks the hardware can genuinely run concurrently) is an important factor to consider.  

***Approaches to  concurrency***

1. Concurrency with multiple-processes

	The first way to make use of concurrency within an application is to divide the application into multiple, separate single threaded processes that are run at the same time.  

	These separate processes can then pass messages to each other through interprocess communication channels (signals, sockets, files, pipes, and so on)  

	```
	precess1 -> interprocess communication <- process2
	```   


2. Concurrency with multiple-threads  

	The alternative approach to concurrency is to run multiple threads in a singl process.  

	Threads are much like lightweight processes: each thread runs independently of the others,and each thread may run a different sequence of instructions.  

	But all threads in a process share the same address space, and most of the data can be accessed directly from all threads.  

	```
	thread1 -> shared memory <- thread2
	```

***Sleeping Barber Problem***

In computer science, the sleeping barber problem is a classic inter-process
communication and synchronization problem between multiple operating system processes.

The problem is analogous to that of keeping a barber working when there are customers,
resting when there are none, and doing so in an orderly manner.

The analogy is based upon a hypothetical barber shop with one barber.
The barber has one barber chair and a waiting room with a number of chairs in it.
When the barber finishes cutting a customer's hair, they dismiss the customer
and go to the waiting room to see if there are other customers waiting.
If there are, they bring one of them back to the chair and cut their hair.
If there are no other customers waiting, they return to their chair and sleep in it.

Each customer, when they arrive, looks to see what the barber is doing.
If the barber is sleeping, the customer wakes them up and sits in the chair.
If the barber is cutting hair, the customer goes to the waiting room.
If there is a free chair in the waiting room, the customer sits in it and waits
their turn. If there is no free chair, the customer leaves.

Based on a naïve analysis, the above description should ensure that the shop functions
correctly, with the barber cutting the hair of anyone who arrives until there are
no more customers, and then sleeping until the next customer arrives. In practice,
there are a number of problems that can occur that are illustrative of general
scheduling problems.

The problems are all related to the fact that the actions by both the barber and
the customer (checking the waiting room, entering the shop, taking a waiting room
chair, etc.) all take an unknown amount of time. For example, a customer may
arrive and observe that the barber is cutting hair, so he goes to the waiting room.
While they're on their way, the barber finishes their current haircut and goes to
check the waiting room. Since there is no one there (the customer not having
arrived yet), they go back to their chair and sleep. The barber is now waiting
for a customer, but the customer is waiting for the barber. In another example,
two customers may arrive at the same time when there happens to be a single
seat in the waiting room. They observe that the barber is cutting hair, go to
the waiting room, and both attempt to occupy the single chair.

Many possible solutions are available. The key element of each is a mutex, which ensures that only one of the participants can change state at once. The barber must acquire this mutual exclusion before checking for customers and release it when they begin either to sleep or cut hair. A customer must acquire it before entering the shop and release it once they are sitting in either a waiting room chair or the barber chair, and also when they leave the shop because no seats were available. This eliminates both of the problems mentioned in the previous section. A number of semaphores is also required to indicate the state of the system. For example, one might store the number of people in the waiting room.

The following pseudocode guarantees synchronization between barber and customer and is deadlock free, but may lead to starvation of a customer. The problem of starvation can be solved by utilizing a queue where customers are added as they arrive, so that barber can serve them on a first come first served basis (FIFO => First In, First Out) The functions wait() and signal() are functions provided by the semaphores. In c-code notation, a wait() is a P() and a signal() is a V().

```
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
```
