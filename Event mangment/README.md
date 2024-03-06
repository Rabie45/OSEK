# Event mechanism
  ## The event mechanism 
    -  is a means of synchronisation 
    -  is only provided for extended tasks 
    -  initiates state transitions of tasks to and from the waiting state. 
They are not independent objects, but assigned to extended tasks. Each extended task has a definite number of events. This task is called the owner of these events.Events can be used to communicate binary information to the extended task to which they are assigned. 
An extended task in the waiting state is released to the ready state if at least one event for which the task is waiting for has occurred. If a running extended task tries to wait for an event and this event has already occurred, the task remains in the running state. 

![image](https://github.com/Rabie45/OSEK/assets/76526170/16806b57-3fdd-4132-8347-99c3f7d78357)

illustrates the procedures which are effected by setting an event: Task T1 waits for an event. Task T2 sets this event for T1. The scheduler is activated. Subsequently, T1 is transferred from the waiting state into the ready state. Due to the higher priority of T1 this results in a task switch, T2 being preempted by T1. T1 resets the event. Thereafter T1 waits for this event again and the scheduler continues execution of T2. 

![image](https://github.com/Rabie45/OSEK/assets/76526170/03f2a208-3e98-4641-bb03-c8010ad09384)

If non preemptive scheduling is supposed, rescheduling does not take place immediately after the event has been set (see Figure 7-2, where extended task T1 is of higher priority) 
