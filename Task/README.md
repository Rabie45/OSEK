# Task management
 ## Task concept 
Complex control software can conveniently be subdivided in parts executed according to their real-time requirements. These parts can be implemented by the means of tasks. A task provides the framework for the execution of functions. 
he OSEK operating system provides a task switching mechanism>
 ## Task types in OSEK:
  - Basic        - Extended 
 Basic Tasks only release the processor, if  they terminate, the OSEK operating system switches to a higher-priority task, or an interrupt occurs which causes the processor to switch to an interrupt service routine (ISR). 
 Extended Tasks diffrent from basic that extended could be in waiting state 

 ## Task state model
  - A task has to change between several states.
Extended tasks Extended tasks have four task states: 

  - running: the task is actively being executed
  - ready: means the task waiting for allocation of the processor 
  - wait: A task cannot continue execution because it shall wait for at least one event 
  - suspended In the suspended state the task is passive and can be activated. 

Comparison of the task types Basic tasks have no waiting state. 

in os API to create Task:
    use DeclareTask(TASK_Name) to create Task
## Activating:
   - Task activation is performed using the operating system services ActivateTask or ChainTask. After activation the task is ready to execute from the first statement. The OSEK operating system does not support C-like parameter passing when starting a task. Those parameters should be passed by message communication or by global variables. 
 
## Multiple requesting of task activation 
The number of multiple requests in parallel is defined in a basic task specific attribute during system generation.
this number would be defined in the oil (osek implemntation lang) file system of the task.

## Task priority: 

  - The scheduler decides on the basis of the task priority (precedence) which is the next of the ready tasks to be transferred into the running state. 
    0 is the lowest
  - Tasks on the same priority level are started depending on their order of activation. -
## The following fundamental steps are necessary to determine the next task to be processed:
 - The scheduler searches for all tasks in the ready/running state.
 - From the set of tasks in the ready/running state, the scheduler determines the set of tasks with the highest priority.
 - Within the set of tasks in the ready/running state and of highest priority, the scheduler finds the oldest task. 

## Full preemptive scheduling 
Full preemptive scheduling will put the running task into the ready state, as soon as a higherpriority task has got ready. The task context is saved so that the preempted task can be continued at the location where it was preempted.

## Non preemptive scheduling 
Non preemptive scheduling imposes particular constraints on the possible timing requirements of tasks. 

## To terminate task use this API 
TerminateTask(task_name)


the code below show an example of oil file and c code of how to create and detminate task 


TASK my task{
PRIORITY =1; refer to static pirority of the task 
AUTOSTART =FASLE this mean suspended     true mean ready
ACTIVATION = 1; activation number that mentiond below
SCHEDULE = NON; STACKSIZE = 32768
STACKSIZE= 20000 Target specific extension Here, the size of the stack. The stack has to be large enough to push 2 Unix signals frames
};
example for 3 tasks  A,B and C 
C is the highest 
A is the lowest 


A is Autostart then A will activate B 
B will terminate it self 
back to A will activate B  