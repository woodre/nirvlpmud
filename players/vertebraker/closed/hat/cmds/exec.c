/* nice little cmd that runs lines of code w/o creating an obj */
#include "/players/vertebraker/define.h"
#define JUNK "/players/vertebraker/closed/junk.c"

main(str) {
  string err;
   if(!str) {
      FAIL("You must supply some code.\n");
      return 0; }
   destruct(JUNK);
   rm(JUNK);
  write_file(JUNK, "#include \"/players/vertebraker/define.h\"\n"+
      "execute_file() {\n"+
      str+"\n"+
      " return 1; }\n");
   if(err = catch(JUNK->execute_file())) { write(err); return 1; }
   destruct(JUNK);
   rm(JUNK);
   return 1; }

get_help() {
    string help;
    help = "Run code, without an object";
    return help;
}
