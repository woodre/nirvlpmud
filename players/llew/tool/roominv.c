#include "/players/llew/closed/ansi.h"

roominv(string who) {
   object *allinv;
   int x,so;

   if (!who)
      allinv=all_inventory(environment(this_player()));
   else if (!find_player(who))
   {
      write ("That player does not exist.\n");
      return 1;
   }
   else
      allinv = all_inventory(environment(find_player(who)));

   for(x=0,so=sizeof(allinv);x<so;x++) {
      write(BOLD+"*Object*--> "+NORM);
      write(allinv[x]);
      write(HIB+" ["+NORM);
      if(allinv[x]->short()) write(allinv[x]->short());
      else if(allinv[x]->query_name()) write(allinv[x]->query_name());
      else if(allinv[x]->query_id()) write(allinv[x]->query_id());
      else write("*INVISIBLE*");
      write(HIB+"]\n"+NORM);
   }
   return 1;
}
