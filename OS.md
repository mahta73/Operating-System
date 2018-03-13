
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
In turn, applications themselves often need to safely execute untrusted third party     code. An example is a web browser executing embedded Javascript to draw a   web page.   Without protection, a script with an embedded virus can take control of   the browser,   making the user think they are interacting directly with the web when   in fact their   web passwords are being forwarded to an attacker.    
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

Hardware support to differentiate between at least two modes of operations, mode bit added to computer hardware to indicate the current mode.

1. user mode: execution done on behalf of a user (1)
2. kernel mode: execution done on behalf of operating system (0)

In user mode, the processor checks each instruction before executing it to verify that the instruction is permitted to be performed by that process.  
In kernel-mode, the operating system executes with protection checks turned off.

At a minimum, the hardware must support three things:  
1. Privileged instructions: All potentially unsafe instructions are prohibited when executing in user-mode.

	Instructions available in kernel-mode, but not in user-mode, privileged instructions.  
	Process isolation is only possible if there is a way to limit programs running in user-mode from directly changing their privilege level.

	The application cannot be allowed to change the set of memory locations it can access
	Another limitation on applications is that they cannot disable processor interrupts.

2. Memory protection: All memory accesses outside of a process’s valid
memory region are prohibited when executing in user-mode.

3. Timer interrupts: Regardless of what the process does, the kernel must have a way to periodically regain control from the current process.


***Memory Protection***

Operating system must provide memory protection. In order to have memory
protection, add two registers that determine the range of legal addresses a program
may access:

base register: holds the smallest legal physical memory address.  

Limit register: contains the size of the range memory outside the defined range is protected.

***system calls***

system calls provide the interface between a running program and the operating system.
Three general methods are used to pass parameters between a running program
and the operating system:  
1. pass parameters in registers.

2. store the parameters in a table in memory, and the table address is passed
as a parameter in a register

3. push (store) the parameters onto the stack by the program, and pop off the stack
by the operating system.

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

	 precess1 -> interprocess communication <- process2   


	2. Concurrency with multiple-threads  

	The alternative approach to concurrency is to run multiple threads in a singl process.  

	Threads are much like lightweight processes: each thread runs independently of the others,and each thread may run a different sequence of instructions.  

	But all threads in a process share the same address space, and most of the data can be accessed directly from all threads.  

	 thread1 -> shared memory <- thread2 
