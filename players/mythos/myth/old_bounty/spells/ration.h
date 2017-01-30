#include "/players/mythos/closed/guild/name.h"
ration(str) {
object ob,corpse;
string msg, msg2;
int value;
  if(!str) { write("Usage: ration <type of ration you wish to turn corpse into>\n"+
                   "       Types available: soak, intox, stuff\n"); return 1; }
  if(str != "stuff" && str != "intox" && str != "soak") return 0;
  corpse = present("corpse",etp);
  if(!corpse) { write("There is no corpse in your surroundings.\n"); return 1; }
  value = corpse->heal_value();
  if(tsp < 1) { write("You do not have enough sp.\n"); return 1; }
  if(value > 45) value = 45; /* if for some unknown reason the player
                                kills a level 50 or greater monster */
  if(tsp < value) value = tsp;
  ob = clone_object("/players/mythos/bounty/spells/ration.c");
  ob->set_type(str);
  ob->set_etype(formtype);
  ob->set_heal(value);
  move_object(ob,etp);
  if(formtype == "tech") {
    if(str == "stuff") { msg = "\n"; msg2 = "\n"; }
    if(str == "soak") { msg = "\n"; msg2 = "\n"; }
    if(str == "intox") { msg = "\n"; msg2 = "\n"; }
  }
  else {
    if(str == "stuff") { msg = "\n"; msg2 = "\n"; }
    if(str == "soak") { msg = "\n"; msg2 = "\n"; }
    if(str == "intox") { msg = "\n"; msg2 = "\n"; }
  }
  write(msg);
  say(msg2);
  tp->add_spell_point(-value);
  destruct(corpse);
return 1; }
