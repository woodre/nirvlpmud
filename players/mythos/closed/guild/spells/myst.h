#include "/players/mythos/closed/guild/def.h"
myst() {
object ob;
if(qtf < 2) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 10) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 1000) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob = clone_object("/players/mythos/closed/guild/spells/mist.c");
ob->set_chance(5*qtf);
move_object(ob,environment(tp));
tp->add_spell_point(-10);
pp->add_sacrifice(-1000);
write("You summon a patch of myst to dim the painful light.\n");
say(capitalize(tpn)+" whistles softly.\n");
tell_room(environment(tp),"Mys"+GRN+"t roll"+NORM+HIG+"s in.....\n"+NORM);
return 1;}
