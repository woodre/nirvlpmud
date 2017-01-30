#include "/players/jenny/define.h"
main(str) {
   if(!str) {
      notify_fail("Say what?\n");
      return 0; }
write("you say:  "+str+"\n");
   say(BOLD+MAG+TPN+" says: "+BOLD+YEL+str+NORM+"\n");
   return 1; }
