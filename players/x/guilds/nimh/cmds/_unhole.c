#include "../x.h"

int cmd_unhole()
{
 int l;
 int lastnum; string x;
 object ob;
 if((string)TP->RN != "x") return 0;
 ob = clone_object("/players/boltar/things/tree");
 sscanf(file_name(ob),"%s#%d",x,lastnum);
 destruct(ob);
 write("Destroying all holes nr. "+(lastnum - 200)+"-"+lastnum+"\n");
 l = lastnum - 200;
 while(lastnum-- > l)
 {
  if(ob=find_object("players/x/guilds/nimh/obj/hole#"+lastnum))
  {
   write("Destructing "+lastnum+"\n");
   destruct(ob);
  }
 }
 write("Done.\n");
 return 1;
}
