#include "/players/mythos/closed/guild/def.h"
reverse() {
object ob, ob2;
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 50) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 5000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(present("reverse",tp)) { write("You already are in reverse mode!\n"); return 1;}
ob = tp->query_attack();
if(!ob) { write("You are not in combat!\n"); return 1;}
if(ob->is_player() && !dpp) { 
write("You may not use this against players right now.\n");
return 1;}
ob2 = clone_object("/players/mythos/closed/guild/spells/reverse.c");
ob2->set_line(tp->query_hp());
move_object(ob2,tp);
write("You intone quietly and the dark fae surrounds you.\n"+
      "You are now in reverse mode.\n");
say(capitalize(tpn)+" intones quietly...\nSlowly, darkness envelops the area....\n");
tell_room(environment(tp),"A thin dark line seems to connect "+capitalize(tpn)+
          " and "+capitalize(ob->query_name())+".\n");
tp->add_spell_point(-50);
pp->add_sacrifice(-5000);
return 1;}
