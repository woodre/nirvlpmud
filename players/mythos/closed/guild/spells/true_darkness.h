#include "/players/mythos/closed/guild/def.h"
true_darkness() {
object ob;
if(qtf < 15) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 150) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 6000) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob = clone_object("/players/mythos/closed/guild/spells/dark_cloak.c");
ob->set_time((random(5)+2)*qtf);
move_object(ob,tp);
tp->add_spell_point(-150);
pp->add_sacrifice(-6000);
write("You summon a cloak of dark fae to protect yourself.\n");
say(capitalize(tpn)+" is suddenly enveloped in a dark mist!\n");
return 1;}
