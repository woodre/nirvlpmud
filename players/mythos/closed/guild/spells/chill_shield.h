#include "/players/mythos/closed/guild/def.h"
chill_shield() {
object ob;
if(qtf < 2) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 40) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 100) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(present("chill_factor",tp)) { write("You already have a chill/cold shield!\n"); return 1;}
ob = clone_object("/players/mythos/closed/guild/spells/cshield.c");
move_object(ob,tp);
ob->set_dam(3);
ob->set_need(100);
tp->add_spell_point(-40);
write("You allow the cold within you to envelope the room.\n"+
      "You may turn it off by typing <cshield_off>.\n");
say("The room suddenly becomes colder.\n");
return 1;}
