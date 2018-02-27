MINISTRY OF EDUCATION AND SCIENCE OF REPUBLIC OF ARMENIA

European Regional Educational Academy of Armenia

Faculty of Information Technology and Business Management

IT Business Management

FINAL PROJECT 







Theme: 		Elevator mutual exchusion problem	

Student:		 Mahta Rezayazdi
Supervisor:  	Prof. T. Kostanyan























yerevan 2018
Table of Contents
Introduction
Chapter1
	1.1 what is an operating system?
	1.2 Operating system design patterns
	Kernels and Processes
	Concurrency
	Memory Management
	Persistent Storage
Chapter2
	Borbershop model
Conclusion
References 












Introduction


. Why I chose Operating system?

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


. Languages

I will do my theisis in c++ and javascript language,






Chapter 1

1.1 What is an operating system?

An operating system is the layer of software that  manages a computer’s resources for its users and their applications.

Operating systems have three roles:

1. Resource sharing: Operating systems play referee.
	. manage shared resources. (The operating system must protect itself and other
	applications from malicious computer viruses. And since the applications are 	sharing physical resources, the operating system needs to decide which
	applications get which resources.)
	. isolate different applications from each other, so that if there is
	a bug in one application, it does not corrupt other applications.

Sharing raises several challenges for an operating system:
. Resource Allocation.
	1. Time Multiplexing: Programs or users take turns i.e. only one at a time. 	Example:Printer.
	2. Space Multiplexing: Instead of completing one by one, each one get some 	part of the resource. Example:Main Memory 
. Isolation.
	An error in one application should not disrupt other applications, or even the 	operating system itself. This is called fault isolation.
	Fault isolation requires restricting the behavior of applications to less than
	the full power of the underlying hardware.
. Communication.
	The flip side of isolation is the need for communication between different 	applications and between different users. In setting up boundaries, an
	operating system must also allow for those boundaries to be crossed in
	carefully controlled ways as the need arises.

2. Mask hardware limitations: Operating systems play illusionist.
	. Operating Systems  provide an abstraction physical hardware to simplify 	application design.
	. Operating systems provide the illusion of a nearly infinite memory, as an 	abstraction on top of a limited amount of physical memory. Likewise, operating 	systems provide the illusion that each program has the computer’s processors 	entirely to itself. Obviously,the reality is quite different! These illusions enable 	applications to be written independently of the amount of physical memory on 	the system or the physical number of processors. 
	The operating system does so through a concept called virtualization. 
	With the right hardware and operating system support, most physical resources
	can be virtualized. Even the type of processor can be virtualized.
	Some operating systems virtualize the entire computer, to run the operating 	system as an application running on top of another operating system.
	This is called creating a virtual machine. The operating system running in the 	virtual machine,called the guest, operating system, thinks it is running on a real, 	physical machine, but this is an illusion presented by the true operating system 	running underneath. Another reason for virtual machines is as an aid in  	debugging. Moreover, the illusion of atomic updates to data structures is
	provided by the operating system using some specialized mechanisms provided
	in hardware.


3. Common services: Operating systems provide glue.
	. Operating system provides a set of common, standard services to applications 	to simplify and regularize their design. An important reason for the operating 	system to provide common services  is to facilitate sharing between	applications.
	. Another standard service in most modern operating systems is the graphical
	user interface library. This facilitates a common “look and feel” to users, so that 	frequent operations such as pull down menus and “cut” and “paste” are 	handled consistently across applications.

1.2 Operating system design patterns














Chapter 2







                                











References
1. 