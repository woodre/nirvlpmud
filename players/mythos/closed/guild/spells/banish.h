#include "/players/mythos/closed/guild/def.h"
banish() {
object ob;
if(qtf < 1) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 5) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 30) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob = present("nightmare",environment(tp));
if(!ob) { write("A nightmare is not here to banish!\n"); return 1;}
if(ob->query_level() > qtf) { write("The nightmare is much too tough to banish with your abilities!\n");
return 1;}
destruct(ob);
tp->add_spell_point(-5);
pp->add_sacrifice(-30);
write("With a wave of a hand you banish the nightmare.\n");
say("A Demonling is banished by "+capitalize(tpn)+".\n");
return 1;}
