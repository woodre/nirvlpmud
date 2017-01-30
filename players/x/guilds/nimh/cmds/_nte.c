#include "../x.h"

int cmd_nte(string str)
{
 if(!str) return 0;
 return (int)MASTER->broadcast(":"+str);
}
