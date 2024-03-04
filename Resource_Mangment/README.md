# Resource management 
The resource management is used to co-ordinate concurrent accesses of several tasks with different priorities to shared resources,

## Resource management ensures that 
 - two tasks cannot occupy the same resource at the same time.
 -  priority inversion can not occur. 
 -  deadlocks do not occur by use of these resources. 
 - access to resources never results in a waiting state.
If the resource management is extended to the interrupt level it assures in addition that
 - two tasks or interrupt routines cannot occupy the same resource at the same time. 

## The functionality of resource management is useful in the following cases: 
 - preemptable tasks 
 - non preemptable tasks, if the user intends to have the application code executed under other scheduling policies, too 
 - resource sharing between tasks and interrupt service routines 
 - resource sharing between interrupt service routines

## Scheduler as a resource:
The scheduler could be locked if the task preempted it self.
 
## Types:
 - Semaphore (bianary - counting ): a semaphore is a synchronization primitive used to control access to shared resources by multiple threads or processes within a program.
 - Mutex:A mutex, short for mutual exclusion object, is a synchronization primitive used in concurrent programming to ensure only one thread can access a shared resource at a time. This prevents race conditions, which occur when multiple threads attempt to modify the same data simultaneously, potentially leading to unexpected results or data corruption.

## Problems:
 
 - Priority inversion:
	sppouse we have 2 Tasks A and B with priority 10 and 11 respectivly with shared resource (variable i) if Task A is running task B suspended no problem 
but if task b is ready task a should be wait and task b start running but both of them use variable i  then to stop task b modifing task a resource so task b turns to blocked state even if task b is higher priority this is called priority inversions
(it arises when a high-priority task is unintentionally delayed by a lower-priority task, essentially inverting the intended execution order based on priority levels.)

'''To slove this problem we should use semaphore to lock the resource to be modified until it complete executing'''  


 - Deadlock
       A deadlock is a situation in an operating system where a set of processes are blocked forever because each process is holding a resource and waiting for another resource that is currently being held by another process in the same set. This creates a circular dependency, preventing any of the processes from making further progress.
   - Example:
		The following scenario results in a deadlock (see Figure 8-2):  Task T1 occupies the semaphore S1 and subsequently cannot continue running, e.g. because it is waiting for an event. Thus, the lower-priority task T2 is transferred into the running state. It occupies the semaphore S2. If T1 gets ready again and tries to occupy semaphore S2, it enters the waiting state again. If now T2 tries to occupy semaphore S1, this results in a deadlock.


![image](https://github.com/Rabie45/OSEK/assets/76526170/4ca82aed-8f26-48cd-a869-80c4aa007e19)


## OSEK Priority Ceiling Protocol: 
The Priority Ceiling Protocol (PCP) is a synchronization protocol used in real-time systems to prevent deadlock and unbounded priority inversion. It ensures that high-priority tasks are not indefinitely blocked by lower-priority tasks, guaranteeing predictable and timely task execution.

Here's how the Priority Ceiling Protocol works:

Ceiling Priority: Each resource (e.g., semaphore, mutex) is assigned a ceiling priority, which is equal to the highest priority of any task that might access the resource. This priority is statically determined during system design.
Acquiring a Resource: When a task attempts to acquire a resource, the following occurs:
The task checks if it has a priority higher than the ceiling priority of the resource.
If yes, the resource is acquired, and the task proceeds.
If no, the task is blocked, and its priority is temporarily boosted to the ceiling priority of the resource. This prevents lower-priority tasks from acquiring the resource while the higher-priority task is waiting.
Releasing a Resource: When a task releases a resource:
Its original priority is restored.
If any higher-priority tasks were previously blocked waiting for the resource, they are now unblocked and can potentially resume execution.
Benefits of the Priority Ceiling Protocol:

Prevents deadlock: By ensuring no lower-priority task can hold a resource while a higher-priority task is waiting, PCP eliminates the possibility of circular dependencies and deadlocks.
Bounds priority inversion: While some priority inversion can still occur, it is limited to the duration it takes for the lower-priority task to finish using the resource. This guarantees that high-priority tasks are not indefinitely delayed by lower-priority ones.
Simple and efficient: PCP is considered a relatively simple and efficient protocol to implement compared to some alternatives.
Limitations of the Priority Ceiling Protocol:

Increased complexity during design: Assigning appropriate ceiling priorities to resources requires careful system design and consideration of all potential task interactions with resources.
Potential for priority escalation: Boosting task priorities can potentially lead to unintended consequences if not carefully managed, such as increased context switching overhead.

OSEK Priority Ceiling Protocol with extensions for interrupt levels ( U can read this part from the articel page 32)





  
