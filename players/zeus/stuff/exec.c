/* vertebraker's code */
/* nice little cmd that runs lines of code w/o creating an obj */
#include "../std.h"
#define JUNK "/players/vertebraker/misc/junk.c"
main(str) {
   if(!str) {
      FAIL("You must supply some code.\n");
      return 0; }
   destruct(JUNK);
   rm(JUNK);
   write_file(JUNK,"#include \"../define.h\"\n"+
      "execute_file() {\n"+
      str+"\n"+
      " return 1; }\n");
   JUNK->execute_file();
   destruct(JUNK);
   rm(JUNK);
   return 1; }
