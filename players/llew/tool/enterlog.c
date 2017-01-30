#include "/players/llew/closed/ansi.h"

enterlog() {
   write("\t\t\t\t"+BOLD+"Enter Log"+NORM+"\n");
   write(HIB+pad("",80,'~')+NORM+"\n");
   write("Name         Level  Guild      Area      Date\n");
   write(HIB+pad("",80,'~')+NORM+"\n");
   tail("/players/llew/closed/logs/enterlog");
   write(HIB+pad("",80,'~')+NORM+"\n");
   return 1;
}
