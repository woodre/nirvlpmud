#include "../def.h"

int cmd_rehash(string str)
{
 if(str) return 0;

 write(HIB+"Rehashing guild commands...\n"+NORM);
 PO->add_cmds();
 write(HIB+"Done.\n"+NORM);
 return 1;
}
