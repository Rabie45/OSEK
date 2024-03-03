/*



*/
#include "os.h"
// define 3 tasks 
DeclareTask(TaskA);
DeclareTask(TaskB);
DeclareTask(TaskC); 


void SystemInit(){
	
}

void delay(uint32_t i)
{
   while(i){i--;}
}

int main(void)
{
  StartOS();
  while(1); 
  return 0;
}

TASK(TaskA)
{
    
   while(1)
   {
      delay(1000);      
      ActivateTask(TaskB);/*TaksA is preemtable. This is a scheduling point*/
      ActivateTask(TaskC);       
   }
}
TASK(TaskB)
{
 
   delay(1000);
   TerminateTask();
}

TASK(TaskC)
{
   delay(1000);   
   TerminateTask();
}

