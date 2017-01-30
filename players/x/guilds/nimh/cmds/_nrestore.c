#include "../x.h"

int cmd_nrestore(string str)
{
 if(str) return 0;

 write(HIK+"Restoring guild statistics...\n"+NORM);
 PO->restore_me();
 write("Ok.\n");
 return 1;
}
