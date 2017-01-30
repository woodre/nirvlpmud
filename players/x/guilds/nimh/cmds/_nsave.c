#include "../x.h"

int cmd_nsave(string str)
{
 if(str) return 0;

 write(HIK+"Saving guild statistics...\n"+NORM);
 PO->save_me();
 write("Ok.\n");
 return 1;
}
