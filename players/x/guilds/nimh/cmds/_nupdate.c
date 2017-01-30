#include "../x.h"

int cmd_nupdate(string str)
{
 if(str) return 0;

 write(HIK+"Updating guild object...\n"+NORM);
 destruct(PO);
 MO(CO(OBJFILE), TP);
 if(!MASTER->query_rat(TP)) MASTER->add_rat(TP);
 write("Ok.\n");
 return 1;
}
