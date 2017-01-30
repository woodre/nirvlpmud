#include "../DEFS.h"


status main(string str)
{
  write("Your credit balance is: @ " + 
    IPTP->balance() + "/" + MAX_CREDITS + "\n");
  return 1;
}
