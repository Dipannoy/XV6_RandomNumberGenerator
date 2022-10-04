#include "types.h"
#include "stat.h"
#include "user.h"
//#include <stdio.h>
#include <stdint.h>

int main(void)
{
  int processId = 1;
  int niceValue = 100;
  int updatedNice = setnice(processId,niceValue);
  if(updatedNice == -1)
  {
    printf(1,"The nice value can't be set for the process with id %d", processId);
    printf(1,". No process is found with this id.");
  }
  else
  {
    printf(1,"The nice value with process id %d", processId);
    printf(1, " is %d\n", updatedNice);
  } 
  exit();
}

