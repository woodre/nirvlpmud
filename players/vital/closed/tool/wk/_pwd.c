/* stupid replacement for the standard */
#include <ansi.h>

main()
{
  write("pwd: "+this_player()->get_path()+"\n");
  return 1;
}

get_help()
{
  string help;
  help = "Returns present working directory";
  return help;
}
