#include "/players/llew/closed/ansi.h"

rs(com) {
   string do_com;
   if(!com) return 0;
   write("The "+BLU+"Rune"+NORM+" glows.\n");
   while(sscanf(com,"%s`%s",do_com,com)==2) 
      command(do_com,this_player());
   command(com,this_player());
   write("The "+BLU+"Rune"+NORM+" dims.\n");
   return 1;
}
