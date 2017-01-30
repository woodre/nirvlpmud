/* nice little cmd that runs lines of code w/o creating an obj */
#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

#define JUNK "/players/vital/closed/junk.c"

main(str)
{
  if(!str)
  {
    notify_fail("You must supply some code.\n");
    return 0;
  }
  destruct(JUNK);
  rm(JUNK);
  write_file(JUNK,"#include \"/players/vital/closed/headers/vital.h\"\n\
#include \<ansi.h\>\nint a, b, c;\n\
execute_file() {\n" + str + "\nreturn 1; }\n");
  if(catch(JUNK->execute_file())) { write("Failure to load.\n"); return 1; }
  destruct(JUNK);
  rm(JUNK);
  return 1;
}

get_help()
{
    string help;
    help = "Run some code, without an object";
    return help;
}
