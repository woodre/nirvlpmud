#include "../x.h"

int cmd_nta(string str)
{
 if(!str) return 0;
 return (int)MASTER->broadcast(">"+str);
}
