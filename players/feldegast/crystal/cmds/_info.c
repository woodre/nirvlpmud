#include "../defs.h"

int do_cmd(string str)
{
  if(!str)
    str = "general";
  if(exists(HELP_DIR + str))
    cat(HELP_DIR + str);
  else
    write("There is no information on that topic.\n");
  return 1;
}
