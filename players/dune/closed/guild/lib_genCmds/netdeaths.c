#include "../DEFS.h"
#define DEATHLOG OBJDIR+"/deaths.txt"

status main(string str) {
   call_other("/players/dune/closed/guild/objects/deathlog.c","deathlog");
   write("You tap into the cybernet to check on recent player deaths...\n\n");
  write(LINE+BOLD+YELLOW);
   write("     Player        Time                     Killed by\n");
   write(OFF+LINE);
   if(!str) tail(DEATHLOG);
   else if(str == "stat") {
     tail("/log/DEATHS");
      write(LINE);
     return 1;
   }
   else if(str == "all") call_other(MORED, "more_file", DEATHLOG);
   write("\n");
write("Level scale:  Newbie "+GREEN+"Low "+BOLD+YELLOW+"Mid "+OFF+RED+"High "+BOLD+MAGENTA+"Great "+BOLD+BLUE+"Godlike\n"+OFF);
write(LINE+"\n");
write("Usage: netdeaths <stat/all>\n");
   return 1;
}
