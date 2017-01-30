/* reads the inventory of a player's environment */
#include "/players/jenny/define.h"
main(str) {
   int x;
   string short_desc; object freak; string *mess;
   if(!str) {
      notify_fail("Syntax: 'IR <freak>'\n");
      return 0; }
   freak = find_player(str);
   if(!freak) {
      notify_fail("Freak not logged on.\n");
      return 0; }
   mess = all_inventory(ENV(freak));
   write(BOLD+"\t\t-=[ "+CAP(str)+"'s Room's Inventory ]=-\n"+NORM);
   write("ROOM FILE NAME: "+HIR+file_name(ENV(freak))+NORM+"\n");
   for(x=0;x<sizeof(mess);x++) {
      if(!mess[x]->short()) short_desc ="("+HIW+"INVIS"+NORM+")";
      else short_desc = mess[x]->short();
      write(HIB+x+NORM+": "+short_desc+" "+HIR+file_name(mess[x])+NORM+"\n"); }
   return 1; }
