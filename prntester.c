#include "types.h"
#include "stat.h"
#include "user.h"
#include <stdint.h>

int main(void)
{

    int elem1,elem2,elem3,elem4,elem5,elem6,counter;

    int *elem1Addr = &elem1;
    int *elem2Addr = &elem2;
    int *elem3Addr = &elem3;
    int *elem4Addr = &elem4;
    int *elem5Addr = &elem5;
    int *elem6Addr = &elem6;
    int *counterAddr = &counter;


    *elem1Addr =10;
    *elem2Addr =200;
    *elem3Addr =400;
    *elem4Addr =130;
    *elem5Addr =500;
    *elem6Addr =0;
    *counterAddr = 20;
    int randomNumber = 0;  
    printf(1,"Two hundred random numbers have been generated ranged 0 to 999 inclusive. \n");
    for(int i=0;i<200;i++)
    {
      randomNumber =  generateprn(elem1Addr,elem2Addr,elem3Addr,elem4Addr,elem5Addr,elem6Addr,counterAddr);

      printf(1,"%d\n", randomNumber);
    }
    printf(1,"Two hundred random numbers have been generated ranged 0 to 999 inclusive. \n");



  exit();
}



