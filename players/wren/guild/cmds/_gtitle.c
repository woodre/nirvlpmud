#include "../def.h"

int cmd_gtitle(string str)
{
 if(str) return 0;

 TP->set_title((string)PO->query_guild_title());
 write(HIB+"Ok.\n"+NORM);
 write("You are now: "+TP->short()+".\n");
 return 1;
}
