# Alarms
 The OSEK operating system provides services for processing recurring events.


## Counters
 A counter is represented by a counter value, measured in ”ticks”, and some counter specific constants.

## Alarm management
  - An alarm-callback routine is a short function provided by the application.
  - An alarm will expire when a predefined counter value is reached. This counter value can be defined relative to the actual counter value

## Alarm Types
  - Single alarm: fire ine time in life
  - cyclic alarm: fire one type with alarm time and every clyclic time fires 

 # API:

## For OIL file
  -   ALARM Alarm_name{
       - COUNTER = MainCounter; main counter main as mentioned n the paper that os use the built in systick timer 
              - ACTION = ACTIVATETASK  {   the action happen if alarm fires to execute the task name 
                        TASK = TAsk_name
                };
                AUTOSTART = TRUE {   the alarm autostarted mean wakes up with the system  and 
                        ALARMTIME = specific tick to fire; 
                        CYCLETIME = 0 for one time per life   number to run periodic;
            };
   };      
 
  -  COUNTER Counter_name {
                MINCYCLE = 1; start counting 
                MAXALLOWEDVALUE = 0xFFFFFFFF; max number to count to 
                TICKSPERBASE = 1;  increase on tick per time 
	};


## For C file
1 - declare task
2 - create task for alarm handling
3 - create task for alarm init 