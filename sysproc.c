#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include <stdint.h>



int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
//return the year of which
//Unix version 6 was released

int 
sys_getyear(void) 
{

return 2022;
} 

int
sys_setnice(int procId, int niceValue)
{
  int niceVal;
  int processId;
  argint(1, &niceVal);
  argint(0, &processId);
  int result = setprocnice(processId,niceVal);
  return result;


}
int sys_generateprn(int *e1, int *e2, int *e3, int *e4, int *e5, int *e6, int *cnt)
{
    
    int elem1,elem2,elem3,elem4,elem5,elem6,counter; 
    argint(0,&elem1);
    argint(1,&elem2);
    argint(2,&elem3);
    argint(3,&elem4);
    argint(4,&elem5);
    argint(5,&elem6);
    argint(6,&counter);
    int *elem1Val = (int *)elem1;
    int *elem2Val = (int *)elem2;
    int *elem3Val = (int *)elem3;
    int *elem4Val = (int *)elem4;
    int *elem5Val = (int *)elem5;
    int *elem6Val = (int *)elem6;
    int *counterVal = (int *)counter;
    
    int temp  = *elem5Val;
    int store  = *elem1Val;  
    *elem5Val = *elem4Val;
    *elem4Val = *elem3Val;
    *elem3Val = *elem2Val;
    *elem2Val = store;
 
    temp ^= temp >> 2;
    temp ^= temp << 1;
    temp ^= store ^ (store << 4);
    *elem1Val = temp;
    *counterVal += 362437;
    *elem6Val = temp + *counterVal;
   int value = *elem6Val;
   int numberOfDigit = 1;
   while(value/10 != 0)
   {
       value = value/10;
       numberOfDigit++;
   }
    int middle = 0;
    
    value = *elem6Val;
    if(numberOfDigit%2==1)
    {
        middle = (numberOfDigit + 1)/2;
    }
    else
    {
        middle = numberOfDigit/2;
    }
    int finalVal = 0;
    int reminder = 0;
    if(numberOfDigit > 3)
    {
    for(int i=1;i<=middle+1;i++)
    {
        reminder = value%10;
        value =value/10;
        if(i==middle-1)
        {
            finalVal+= reminder;
        }
        else if(i==middle)
        {
            finalVal += reminder*10;
        }
        else if(i == middle+1)
        {
            finalVal += reminder * 100;
        }
       // else if(i == middle+2)
       // {
       //   finalVa += reminder * 1000;
       // }
        else
        {
        }
    }
    
    }
    else
    {
       finalVal = value;
    }
    if(finalVal <0)
    {
       finalVal = finalVal * (-1);
    }
    
                 
    
            
    return finalVal;
}
