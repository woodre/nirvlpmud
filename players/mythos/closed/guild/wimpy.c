#include "/players/mythos/closed/guild/def.h"
string attack, defend;
id(str) { return str == "wimpy_check"; }

set_attacker(str) { attack = str;}

drop() {return 1;}
get() { return 0;}

reset(arg) {
 if(arg) return;
  call_out("check",3);
}
 
init() {
  add_action("rquit","quit");
}
 
check() {
object ob,cu;
ob=find_player(attack);
   if(((ob->query_hp() < (ob->query_mhp())/4) && ob->query_wimpy()) || 
   ob->query_ghost() || !(ob->query_interactive()) || 
   (ob->query_hp() < 20)) {
   ep->heal_self(random(300));
   ep->add_exp((ob->query_level() + ob->query_extra_level()) * 500);
   tell_object(ep,
   "You feel triumphant and more energetic as \n"+
   "you feed on the fear of your opponent!\n");
   cu = clone_object("/players/mythos/closed/guild/curse.c");
   cu->set_feeder(epn);
   cu->set_food(attack);
   cu->savecurse();
   move_object(cu,ob);
   tell_object(ob,"Something very bad has just occured!\n");
   ob->save_me();
   }
   if(ob != ep->query_attack()) { 
   if(ob && present("run_check",ob)) {
   destruct(present("run_check",ob));}
   destruct(this_object()); }
   call_out("check",3);
return 1;}

rquit() {
   present(fear,ep)->add_sacrifice(-1000);
   present(fear,ep)->raise_fae(-1);
   tell_object(ep,"You feel ashamed and filled with loss.\n");
}
