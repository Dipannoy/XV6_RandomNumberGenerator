#include "types.h"
#include "stat.h"
#include "user.h" 
int main(void)
{
  printf(1, "Hello Nice %d\n", setnice(1,100));
  exit();
}
