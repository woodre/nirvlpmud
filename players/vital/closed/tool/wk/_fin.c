#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"

main(str)
{
    object fin;
    fin = CO("/players/mythos/closed/play/finger");
    MO(fin,TP);
    command("fin "+str,TP);
    destruct(fin);
    return 1;
}

get_help()
{
  string help;
  help = "Mythos finger command";
  return help;
}
