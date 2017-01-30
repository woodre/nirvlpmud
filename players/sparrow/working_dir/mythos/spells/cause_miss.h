#include "/players/mythos/closed/guild/def.h"
object ob;
int before;
cause_miss() {
if(qtf < 5) { write("Your control over fae is not enough!\n"); return 1;}
if(scrp < 10000) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(tsp < 175) { write("You do not have enough energy!\n"); return 1;}
  if(!(tp->query_attack())) {write("You may only use this during combat.\n"); return 1;}
  if(!((tp->query_attack())->query_npc()) &&  !dpp) {
    write("You may not use this on players at this time.\n"); return 1;}
  if(present("adder",(tp->query_attack()))) {
  write("That target is already frozen!\n"); return 1;}
  if(present("ooga",(tp->query_attack()))) {
  write("You must wait while the fae gather.\n"); return 1; }
  before = (tp->query_attack())->query_wc();
  (tp->query_attack())->set_wc(random(25 - qtf));
  write("Whispering a few key words you cause your enemy's limbs to freeze!\n");
  say(capitalize(tpn)+" whispers a few words.....\n");
  tp->add_spell_point(-175);
  pp->add_sacrifice(-10000);
  ob = tp->query_attack();
  move_object(clone_object("/players/mythos/closed/guild/spells/adder.c"),ob);
  call_out("dfix",20+qtf);
return 1;}

dfix() {
if(ob) {
  ob->set_wc(before + 20 + random(30));
  destruct(present("adder",ob));
  move_object(clone_object("/players/mythos/closed/guild/spells/ooga.c"),ob);
  tell_room(environment(ob),ob->short()+"'s limbs thaw.\n"); }
return 1;}
