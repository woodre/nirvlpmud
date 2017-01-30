/* reads the inventory of a player */
#include "/players/jenny/define.h"
main(str) {
   int x, y;
   string short_desc; object freak; string *mess;
   if(!str) {
      notify_fail("Syntax: 'I <freak>'\n");
      return 0; }
   freak = find_player(str);
   if(!freak) {
      notify_fail("Freak not logged on.\n");
      return 0; }
   mess = all_inventory(freak);
   write(BOLD+"\t\t-=[ "+CAP(str)+"'s Inventory ]=-\n"+NORM);
   for(x=0;x<sizeof(mess);x++) {
      if(!mess[x]->short()) short_desc ="("+HIW+"INVIS"+NORM+")";
      else short_desc = mess[x]->short();
      write(HIB+x+NORM+": "+NORM+short_desc+NORM+" "+HIR+file_name(mess[x])+NORM+"\n");
      
   }
   return 1; }
