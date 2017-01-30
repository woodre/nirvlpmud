#include <ansi.h>

main(str)
{
  string cmd_set;
  int i, so;
  for(i = 0, so = sizeof(cmd_set = explode(str, ",")); i < so; i++) 
    command(cmd_set[i],this_player());
  return 1;
}

get_help()
{
  string help;
  help = "Issue multiple commands from one line, separate with ,";
  return help;
}
