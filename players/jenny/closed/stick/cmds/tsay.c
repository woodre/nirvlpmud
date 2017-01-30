#include "/players/jenny/define.h"
string blah, blahh;
string str;
main(str) {
   if(!str) {
      notify_fail("Say what?\n");
      return 0; }
str = crypt(str, 0);
blah = explode(str, " ");
write("you say:  "+str+"\n");
   say(blah);
   return 1; }
