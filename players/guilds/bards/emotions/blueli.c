#include "/players/guilds/bards/def.h"

status main(string str){
  object ob;
  
  if (!str) {
    write
    ("You briefly surround yourself with an aura of blue magic.\n");
    say(tp + " surrounds " + TP->query_objective() +
    "self with an aura of sinister blue magic.\n");
    return 1;
  }
  ob = present(str, ENV);
  if (!ob) {
    write(CAP + " is not here right now.\n");
    return 1;
  }
  write(format("You point at " + NAME(ob) + ", and "+PRON(ob)+
      " is surrounded by an aura of pulsating blue magic.\n"));
  say(format(tp + " points at " + NAME(ob) + ", and "+PRON(ob)+
      " is surrounded by an aura of pulsating blue magic.\n"));
  tell_object(ob,format(
    tp +" points at you, and an aura of pulsating blue magic surrounds "+"you.\nYou feel different.\n"));
  return 1;
}
