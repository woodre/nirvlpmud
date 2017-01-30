#include "/players/mythos/closed/guild/def.h"
grand_circle() {
object ob, mem, ask, co;
int num;
num = 0;
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 50) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 200) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!creator(environment(tp))) {
  write("You can not cast that here!\n");
return 1;}
ob = first_inventory(environment(tp));
while(ob) {
  if(present(fear,ob)) { num = num + 1; }
  ob = next_inventory(ob);
  }
if(num < 3) { write("There aren't enough guild members to cast this.\n"); return 1;}
mem = first_inventory(environment(tp));
while(mem) {
  if(present(fear,mem) && mem != tp) { 
  ask = clone_object("/players/mythos/closed/guild/spells/cir_ask.c");
  ask->set_caster(tpn);
  move_object(ask,mem); }
  mem = next_inventory(mem);
  }
  co = clone_object("/players/mythos/closed/guild/spells/cir_count.c");
  co->set_count(1);
  move_object(co,tp);
tp->add_spell_point(-50);
pp->add_sacrifice(-200);
return 1;}
