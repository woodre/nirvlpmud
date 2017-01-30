#include "/players/mythos/closed/guild/def.h"
terror(str) {
object ob;
int rnj;
if(!str) { write("Usage: terror <who>\n"); return 1;}
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 35) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 1000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!present(str,environment(tp))) { write("That is not here.\n"); return 1;}
  if(!(present(str,environment(tp))->query_npc()) &&  !dpp) {
    write("You may not use this on players at this time.\n"); return 1;}
rnj = random(10);
if(present(str,environment(tp))->query_npc() &&
   present(str,environment(tp))->query_level() > tp->query_level()) {
  rnj = 1; }
if(rnj > 0) {
if(present("freeze.c",present(str,environment(tp)))) {
  write("You can not freeze the target with fear right now.\n");
return 1;}
ob = clone_object("/players/mythos/closed/guild/spells/freeze3.c");
ob->set_dropped(qtf);
move_object(ob,present(str,environment(tp)));
tell_room(environment(tp),capitalize(tpn)+" stares at "+capitalize(str)+".\n"+
          capitalize(str)+" is reduced to a mass of gibbering flesh as "+
          present(str,environment(tp))->query_pronoun()+" is filled with terror!\n");
tell_object(present(str,environment(tp)),"You feel great DREAD and TERROR!\n"+
            "You can not move!\n"); }
else {
tell_room(environment(tp),capitalize(tpn)+" stares at "+capitalize(str)+".\n"+
          capitalize(str)+" runs in terror!\n");
tell_object(present(str,environment(tp)),"You feel great DREAD and TERROR!\n"+
            "You run!\n"); 
present(str,environment(tp))->run_away(); }
tp->add_spell_point(-35);
pp->add_sacrifice(-1000);
return 1;}
