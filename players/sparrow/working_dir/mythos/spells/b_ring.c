#include "/players/mythos/closed/guild/def.h"

id(str) { return str == "demonring" || str == "ring" || str == "demon ring"; }

short(){return "Demon Ring [basic]";}

long() {
write("A basic demon trapping ring.  It is a dull black color.\n"+
      "To trap a demon/daemon/avatar you must type 'trap <name>'\n.");
}

drop() {return 0;}
get() { return 1;}
query_gsave() { return 1;}
query_save_flag() { return 0;}

init() {
  add_action("trap","trap");
}

trap(str) {
object ob, ob2;
int lvl;
  if(!str) { write("Usage: trap <name of thing>\n"); return 1;}
  ob = present(str,environment(tp));
  if(!ob) { write("That is not here.\n"); return 1;}
  if(!(ob->query_npc())) { write("That is not possible.\n"); return 1;}
  if(!call_other(ob,"id","daemon") && !call_other(ob,"id","demon") &&
     !call_other(ob,"id","avatar")) {
  write("That is no avatar, demon, or daemon!\n"); return 1;}
  if(ob->query_hp() > qtf * 20) {
  write("It is still too strong!  You must weaken it!\n"); return 1;}
  lvl = ob->query_level();
  if(lvl > 18) { 
  ob2 = clone_object("/players/mythos/closed/guild/spells/d_ring1.c");
  ob2->set_owner(tpn);
  ob2->set_trapped(ob->short());
  ob2->set_trap_path(ob);
  move_object(ob2,tp); }
  if(lvl > 12 && lvl < 19) { 
  ob2 = clone_object("/players/mythos/closed/guild/spells/d_ring2.c"); 
  ob2->set_owner(tpn);
  ob2->set_trapped(ob->short());
  ob2->set_trap_path(ob);
  move_object(ob2,tp);}
  if(lvl < 13) { 
  ob2 = clone_object("/players/mythos/closed/guild/spells/d_ring3.c"); 
  ob2->set_owner(tpn);
  ob2->set_trapped(ob->short());
  ob2->set_trap_path(ob);
  move_object(ob2,tp);} 
  tell_room(environment(tp),
  "\nSuddenly... a bright light flares up and envelops "+ob->short()+"!\n\n"+
  "Then the light and "+ob->short()+" are gone!\n\n");
  write("You have trapped "+str+" in your ring!\n");
  write("Blood flows from your hand....you see that the ring has cut you a bit.\n");
  tp->add_hit_point(-10 - random(10));
  destruct(ob);
destruct(this_object());
return 1;}
