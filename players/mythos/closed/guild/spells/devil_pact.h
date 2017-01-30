#include "/players/mythos/closed/guild/def.h"
devil_pact() {
object ob;
int c;
if(qtf < 18) { write("Your control over fae is not enough!\n"); return 1;}
if(scrp < 800) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(tsp < 200) { write("You do not have enough energy!\n"); return 1;}
tp->add_spell_point(-200);
pp->add_sacrifice(-800);
write("You beg for the DEVIL to appear......\n");
move_object(clone_object("/players/mythos/closed/guild/spells/devil.c"),tp);
ob = find_player("mythos");
if(ob) { tell_object(ob,HIR+"\n\t"+tpn+" is doing a devil pact!\n\n"+NORM);}
return 1;}
