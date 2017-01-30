#include "/players/mythos/closed/guild/def.h"
darkness() {
object ob;
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 15) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 5000) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob = clone_object("/players/mythos/closed/guild/spells/darkness.c");
ob->set_chance(qtf*10);
move_object(ob,environment(tp));
tp->add_spell_point(-15);
pp->add_sacrifice(-5000);
write("You call up darkness to block the dangerous light.\n");
say(capitalize(tpn)+" whistles softly.\n");
tell_room(environment(tp),"Suddenly.....\n"+BOLD+"DARKNESS shrouds the room....\n"+NORM);
return 1;}
