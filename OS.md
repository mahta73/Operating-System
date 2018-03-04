


# Introduction


## Why I chose Operating system?

There has been a huge amount of innovation in both the principles and practice
of operating systems over the past two decades.

I believe the concepts and principles of operating system are important for anyone getting a degree in computer science or computer engineering. 
The core ideas in operating systems protection, concurrency, virtualization, resource allocation, and reliable storage are widely used throughout computer science.
Anyone trying to build resilient, secure,flexible computer systems needs to have a deep grounding in these topics and to be able to apply these concepts in a variety of settings.

This is especially true in a modern world where nearly everything a user does is distributed, and
nearly every computer is multi-core. 

Operating systems concepts are popping up in many different areas; even web browsers and cloud computing platforms have become mini-operating systems in their own right.

Today, smartphones , phones capable of running independent third party applications , are the fastest growing part of the mobile phone business. These new devices require much more complete operating systems, with sophisticated resource management, multi-tasking, security and failure isolation.

Likewise, automobiles are increasingly software controlled, raising a host of operating system issues. 

Can anyone write software for your car? 
What ifthe software fails while you are driving down the highway? 
How might the operating system of your car be designed to prevent a computer virus from
hijacking control of your car’s computers? 

Although this might seem far fetched, researchers recently demonstrated that they could remotely turn off a car’s braking system through a computer virus introduced into the car’s computers through a hacked car radio. 

A goal of this thesis is to explain how to build more reliable and secure computer systems in a variety of contexts.

Precisely because operating systems concepts are among the most difficult in all of computer science, it is also important to understand how these ideas are applied in practice in real operating systems of today.

# Chapter 1

## 1.1 What is an operating system?

An operating system is the layer of software that  manages a computer’s resources for its users and their applications.

## Operating systems have three roles:

## 1. Resource sharing: Operating systems play referee.

* manage shared resources. 

(The operating system must protect itself and other applications from malicious computer viruses. And since the applications are sharing physical resources, the operating system needs to decide which applications get which resources.)

* isolate different applications from each other, so that if there is a bug in one application, it does not corrupt other applications.

## Sharing raises several challenges for an operating system:

* Resource Allocation.
	1. Time Multiplexing: Programs or users take turns i.e. only one at a time. 	Example:Printer.
	2. Space Multiplexing: Instead of completing one by one, each one get some 	part of the resource. Example:Main Memory 
* Isolation.
	An error in one application should not disrupt other applications, or even the 	operating system itself. This is called fault isolation.
	Fault isolation requires restricting the behavior of applications to less than
	the full power of the underlying hardware.
* Communication.
	The flip side of isolation is the need for communication between different 	applications and between different users. In setting up boundaries, an
	operating system must also allow for those boundaries to be crossed in
	carefully controlled ways as the need arises.

## 2. Mask hardware limitations: Operating systems play illusionist.

* Operating Systems  provide an abstraction physical hardware to simplify application design.

* Operating systems provide the illusion of a nearly infinite memory, as an abstraction on top of a limited amount of physical memory. Likewise, operating systems provide the illusion that each program has the computer’s processors entirely to itself. Obviously,the reality is quite different! These illusions enable applications to be written independently of the amount of physical memory on the system or the physical number of processors. The operating system does so through a concept called virtualization. With the right hardware and operating system support, most physical resources can be virtualized. Even the type of processor can be virtualized.
Some operating systems virtualize the entire computer, to run the operating system as an application running on top of another operating system. This is called creating a virtual machine. The operating system running in the 	virtual machine,called the guest, operating system, thinks it is running on a real,physical machine, but this is an illusion presented by the true operating system running underneath. Another reason for virtual machines is as an aid in debugging. Moreover, the illusion of atomic updates to data structures is provided by the operating system using some specialized mechanisms providedin hardware.

## 3. Common services: Operating systems provide glue.
* Operating system provides a set of common, standard services to applications 	to simplify and regularize their design. An important reason for the operating 	system to provide common services  is to facilitate sharing between	applications.
* Another standard service in most modern operating systems is the graphical
user interface library. This facilitates a common “look and feel” to users, so that 	frequent operations such as pull down menus and “cut” and “paste” are 	handled consistently across applications.

## 1.2 Operating system design patterns

1.3 The Kernel Abstraction

1.3.1 The process concept

A central role of operating systems is protection.

• Reliability
	For high system reliability, an operating system must bullet proof itself so that it 	operates correctly regardless of whatever an application or user might do.

• Security
	For example, if a malicious application is permitted to write directly to the disk, 	it could modify the file containing the operating system’s code, so that the next 	time the system starts, the modified operating system will boot instead, 	installing spyware and disabling virus protection. For security, an operating 	system must prevent untrusted code from modifying system state.

• Privacy
	an operating system must prevent untrusted code from accessing unauthorized 	data.

• Efficiency
	For efficiency and fairness, an operating system must be able to limit the 	amount of resources assigned to each application or user.

Operating system kernel
Implementing protection is the job of the operating system kernel. The kernel is the lowest level of software running on the system, with full access to all of the capabilities of the hardware. The operating system kernel runs directly on
the processor with unlimited rights. Applications need to run on
the processor with all potentially dangerous operations disabled. The kernel is necessarily trusted to do anything that can be done with the hardware. Everything else — that is, the untrusted software running on the system — is run in a restricted environment, with less than complete access to the full power of the hardware.
*/
In turn, applications themselves often need to safely execute untrusted third
party code. An example is a web browser executing embedded Javascript to
draw a web page. Without protection, a script with an embedded virus can take
control of the browser, making the user think they are interacting directly with
the web when in fact their web passwords are being forwarded to an attacker.
*/
Process
The execution of an application program with restricted rights is called a process.
A process’s access to hardware is mediated and checked by the operating system kernel.
The difference between a process and a program is that a process is an instance of a program.
A “process” was originally coined to mean what we now call a “thread”.
A process executes a program, consisting of one or more threads running inside a protection boundary.
Executable image
a programmer types up some code in some appropriately high-level language. A compiler converts that code into a sequence of machine instructions, and stores those
instructions into a file, called the executable image of the program. The compiler
also defines any static data the program needs, along with their initial values,
and includes them in the executable image. To start the program running, the operating system copies the program instructions and data from the executable image into physical memory.

Process Control Block
The process control block stores all the information the operating system needs about a particular process:where it is stored in memory, where its executable image is on disk, which user asked it to start executing, what privileges the process has, and so forth.

1.3.1 Dual-mode operation












Chapter 2







                                











References
1. 
