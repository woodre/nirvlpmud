/*
Feel free to clone this object for your area, or for your personal use.
-Feldegast
*/
#include "/players/feldegast/closed/ansi.h"
/* Double duty as pklog.c and pklog */
#define LOGFILE "/players/feldegast/obj/pklog"

short() { return "The PK Notice"; }

long() { 
   write("A large stone rests firmly in the ground, listing the most\n"+
         "recent player killing deaths.  Perhaps you should read it.\n");
}

id(str) {
   return str == "notice" || str == "obituary notice" || str == "obituary";
}

init() {
   add_action("read","read");
}

read(str) {
   if(!str || !id(str)) {
      notify_fail("Read what?\n");
      return 0;
   }
   call_other(LOGFILE,"deathlog",0);
   write(pad("",22)+BOLD+"PK Notice"+NORM+"\n\n");
   write("     Player        Time                     Killed by\n");
   write("\n");
   tail(LOGFILE);
   write("\n");
   write("Level scale:  Newbie "+GRN+"Low "+HIY+"Mid "+NORM+RED+"High "+BOLD+"Great\n"+NORM);
   say(this_player()->query_name()+" reads the pk notice.\n");
   return 1;
}

