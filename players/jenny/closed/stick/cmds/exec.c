#include "/players/jenny/define.h"
#define JUNK "/players/jenny/closed/stick/junk.c"
main(str) {
   if(!str) {
      FAIL("You must supply some code.\n");
      return 0; }
   write_file(JUNK,"#include \"/players/jenny/define.h\"\n"+
      "execute_file() {\n"+
      str+"\n"+
      " return 1; }\n");
   JUNK->execute_file();
   destruct(JUNK);
   rm(JUNK);
   return 1; }
