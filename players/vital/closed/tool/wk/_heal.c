#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str) {
    string who;
    int x;
    object freak;
    if(!str) freak = find_player(this_player());
    else if(sscanf(str,"%s %d",who,x) != 2) {
        freak = find_player(str);
        x = 80000;
    }
    if(!freak) {
        notify_fail(capitalize(str)+" is not logged on.\n");
        return 0;
    }
    freak->heal_self(x);
    write("You heal "+freak->query_name()+".\n");
/*     tell_object(freak, BOLD + GRN +  */
/*       "Your wounds heal and your body is restored.\n" + NORM); */
    return 1;
}

get_help()
{
  string help;
  help = "Heal a player";
  return help;
}
