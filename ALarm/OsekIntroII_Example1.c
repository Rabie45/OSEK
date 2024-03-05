
#include <stdbool.h>
#include <stdint.h>
#include "os.h"


void SystemInit(void) {

}
DeclareTask(Application);
DeclareTask(ApplicationInit);


int main(void) {
  StartOS();
  while (1); 
  return 0;
}

TASK(Application) {

 uint8_t counter = 0u;
  counter ^= 0x2;
  TerminateTask();
}

TASK(ApplicationInit) {
  TerminateTask();
}

