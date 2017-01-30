#include "/players/mythos/closed/guild/def.h"
dismiss() {
object ob;
if(qtf < 1) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 5) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 30) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob = present("nightmare",environment(tp));
if(!ob) { write("A nightmare is not here to dismiss!\n"); return 1;}
if(ob->query_level() > qtf*3/2) {
write("The nightmare is much too tough to dismiss with your abilities!\n");
return 1;}
tp->add_spell_point(- 5 - (ob->query_level()));
pp->add_sacrifice(-30);
destruct(ob);
write("With a wave of a hand you dismiss the nightmare.\n");
say("A Demonling is banished by "+capitalize(tpn)+".\n");
return 1;}
