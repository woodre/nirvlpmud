#include "/players/mythos/closed/guild/def.h"
string attack, defend;
object ob;
id(str) { return str == "run_check"; }

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

rquit() {
object cu;
ob=find_player(attack);
   ob->heal_self(random(300));
   ob->add_exp((ep->query_level() + ep->query_extra_level()) * 500);
   tell_object(ob,
   "You feel triumphant and more energetic as \n"+
   "you feed on the fear of your opponent!\n");
   cu = clone_object("/players/mythos/closed/guild/curse.c");
   cu->set_feeder(attack);
   cu->set_food(epn);
   cu->savecurse();
   move_object(cu,ep);
   tell_object(ep,"Something very bad has just occured!\n");
   ep->save_me();
}

check() {
object cu;
if(!(ep->query_interactive())) {
ob=find_player(attack);
   ob->heal_self(random(300));
   ob->add_exp((ep->query_level() + ep->query_extra_level()) * 500);
   tell_object(ob,
   "You feel triumphant and more energetic as \n"+
   "you feed on the fear of your opponent!\n");
   cu = clone_object("/players/mythos/closed/guild/curse.c");
   cu->set_feeder(attack);
   cu->set_food(epn);
   cu->savecurse();
   move_object(cu,ep);
   tell_object(ep,"Something very bad has just occured!\n"); 
   ep->save_me();}
call_out("check",3);
return 1; }
