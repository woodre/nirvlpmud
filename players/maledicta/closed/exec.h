/* nice little cmd that runs lines of code w/o creating an obj */
#define JUNK "/players/maledicta/junk.c"
main(str) {
   if(!str) {
      write("You must supply some code.\n");
      return 1; }
   write_file(JUNK,"#include \"/players/maledicta/ansi.h\"\n"+
      "execute_file() {\n"+
      str+"\n"+
      " return 1; }\n");
   JUNK->execute_file();
   destruct(JUNK);
   rm(JUNK);
   return 1; }
