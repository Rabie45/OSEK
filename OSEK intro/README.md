# OSEK
 The AUTOSAR (AUTomotive Open System ARchitecture) standard, which is the current industry standard for automotive software, is built upon the foundation laid by OSEK.
 
## OSEK Concepts Part 1
The OSEK operating system is a single processor operating system. The OSEK operating system provides a pool of different services and processing mechanisms.

![image](https://github.com/Rabie45/OSEK/assets/76526170/11b161d9-61eb-464a-bcc0-97eb3dd448fc)

## Task management

  - Activation and termination of tasks

  - Management of task states, task switching

## Synchronization

  The operating system supports two means of synchronization effective on tasks:

   - Resource management Access control for inseparable operations to jointly used (logic) resources or devices, or for control of a program flow.

   - Event control Event management for task synchronisation.

## Interrupt management

![image](https://github.com/Rabie45/OSEK/assets/76526170/4aae4f36-98dc-4823-8252-b9ad9d508743)

    - Services for interrupt processing

## Alarms

    - Relative and absolute alarms

       - Intra processor message handling

    - Services for exchange of data

## Error treatment

    - Mechanisms supporting the user in case of various errors 
 ## Architecture of the OSEK operating system
![image](https://github.com/Rabie45/OSEK/assets/76526170/ff231277-7ea8-4e64-881c-b4602d21ac42)


## Processing levels

    - The OSEK operating system enables a controlled real-time execution of several processes which appear to run in parallel.

      The OSEK operating system provides a defined set of interfaces for the user. These interfaces are used by entities which are competing for the CPU. There are two types of entities:

       - Interrupt service routines managed by the operating system

       - Tasks (basic tasks and extended tasks)
## Then we have to understand what the meaning of task :


    - Task
    ![image](https://github.com/Rabie45/OSEK/assets/76526170/6a614cbe-23cb-4bcd-b8c2-3df291a2379b)

         a task refers to a unit of work or a program that is executed by the computer system. Tasks can be thought of as individual processes or threads that perform specific functions or operations.

             The primary task of an operating system is to manage and coordinate these tasks to ensure the efficient and orderly execution of programs. This involves allocating system resources such as CPU time, memory, and input/output devices to different tasks based on priority and scheduling policies.

## The OS performs various tasks to facilitate the execution of programs, including:

     - Process management 
     - Memory management
     - File system management
     - Device management

These are some of the main tasks performed by an operating system to ensure the proper functioning and coordination of programs and resources within a computer system.

# Lets back to OSEK.

OSEK defines three processing levels:

 - Interrupt level

 - Logical level for scheduler 

## Task level
The following priority rules have been established:

 - Interrupts have precedence over tasks

 - The interrupt processing level consists of one or more interrupt priority levels 

 - Interrupt service routines have a statically assigned interrupt priority level

 - Assignment of interrupt service routines to interrupt priority levels is dependent on implementation and hardware architecture

 - For task priorities and resource ceiling-priorities bigger numbers refer to higher priorities.

The task’s priority is statically assigned by the user
## Conformance classes (simplify the specification of the system requirements)

 Conformance classes exist to support the following objectives:

  - To provide convenient groups of operating system features
  - To allow partial implementations along pre-defined lines.
  - Conformance classes are determined by the following attributes:

 Multiple requesting of task activation

  - Task types
  - Number of tasks per priority

At the end this is part 1 for OSEK Concepts

those word created from this paper https://www.irisa.fr/alf/downloads/puaut/TPNXT/images/os223.pdf
