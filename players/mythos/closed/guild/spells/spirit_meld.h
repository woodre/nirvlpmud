#include "/players/mythos/closed/guild/def.h"
spirit_meld() {
object ob, mem, ask, co;
int num;
num = 0;
if(qtf < 18) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 100) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 1000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(find_living("fear_avatar")) { write("There is another avatar on...\n"); return 1;}
ob = first_inventory(environment(tp));
while(ob) {
  if(present(fear,ob)) { num = num + 1; }
  ob = next_inventory(ob);
  }
if(num < 5) { write("There aren't enough guild members to cast this.\n"); return 1;}
mem = first_inventory(environment(tp));
while(mem) {
  if(present(fear,mem) && mem != tp) { 
  ask = clone_object("/players/mythos/closed/guild/spells/spirit_ask.c");
  ask->set_caster(tpn);
  move_object(ask,mem); }
  mem = next_inventory(mem);
  }
  co = clone_object("/players/mythos/closed/guild/spells/spirit_count.c");
  co->set_count(1);
  move_object(co,tp);
tp->add_spell_point(-100);
pp->add_sacrifice(-1000);
return 1;}
