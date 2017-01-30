#include <ansi.h>

main() { write(ctime(time())+"\n"); return 1; }

get_help()
{
  string help;
  help = "Gives the date and time";
  return help;
}