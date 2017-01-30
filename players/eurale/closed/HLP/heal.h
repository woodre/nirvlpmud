#include "DEF.h"
 
heal(str) {
object ob;
string who;

if(!str) { TP->heal_self(5000);
write("You are completely healed!\n"); return 1; }

  sscanf(str,"%s",who);
  ob = find_player(who);
  if(!ob) { ob = find_living(ob); }
  if(!ob) { write("not logged on... \n"); return 1; }
  ob->heal_self(100000);
  write("You have healed "+capitalize(who)+".\n");
  tell_object(ob,HIW+
    "A blinding white mist settles over you...\n"+
    "Suddenly, it flows into your body through your mouth and nose...\n"+
    "You feel completely energized....\n\n"+NORM);
return 1;
}
