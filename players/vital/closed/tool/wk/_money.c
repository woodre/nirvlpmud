#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str)
{
  string who;
  int x;
  object freak;
  if(!str) freak = find_player(this_player());
    else
  if(sscanf(str,"%s %d",who,x) != 2)
  {
    freak = find_player(str);
    if(!x) x = (80000 - freak->query_money());
  }
  if(!freak)
  {
    notify_fail(capitalize(str)+" is not logged on.\n");
    return 0;
  }
  freak->add_money(x);
  write("You help "+freak->query_name()+" out of debt.\n");
  tell_object(freak,BOLD+GRN+"You suddenly feel burdened with coinage.\n"+NORM);
  return 1;
}

get_help()
{
  string help;
  help = "Add coins to player";
  return help;
}
