/* runs code without building an object */

#include "/players/forbin/define.h"
#define JUNK "/players/forbin/closed/junk.c"

main(str) {
  if(!str) {
    FAIL("You must supply some code.\n");
      return 0; 
  }
  destruct(JUNK);
  rm(JUNK);
  write_file(JUNK,"#include \"../define.h\"\n"+
    "execute_file() {\n"+
    str+"\n"+
    " return 1; }\n");
  if(catch(JUNK->execute_file())) { write("Failure to load.\n"); return 1; }
  destruct(JUNK);
  rm(JUNK);
    return 1; 
}
