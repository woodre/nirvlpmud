/*  
 *  A good full heal- usage up to 3 times
 *  found when /players/mythos/closed/guild/forest/mon/jinro.c
 *  is killed
 *  1 in 50 it calls a ryo up that attacks the user
     potence 1000 type other
 *                                        -mythos
 */

#include "/players/mythos/closed/guild/def.h"
int flesh_heal;

id(str) { return (str == "flesh" || str == "meat"); }

reset(arg) {
if(arg) return;
 flesh_heal = 3;
}

long(){
  write("The flesh of the Jinro.  Eat it and you\n"+
        "will become whole.  Sometimes strange things\n"+
        "can happen.\n");
}

short() { return "Flesh of the Jinro"; }

drop() { return 0;}
get() { return 1;}
query_weight() { return 4; }
query_value() { return flesh_heal*10000; }
query_save_flag() { return 1;}
is_heal() { return "other"; }
query_potence() { return 1000; }

init(){
  add_action("eat","eat");
}

eat(str) {
object obb;
if(this_player() != environment(this_object())) return 0;
  if(!str) return 0;
  if(str == "flesh" || str == "meat") {
  write("You eat the flesh of the Jinro.\n");
  write("You feel whole!\n");
  say(capitalize(tpn)+" eats some flesh.\n");
  
  tp->heal_self(1000);;
  
  if(random(50)==0) {
    obb=clone_object("/players/mythos/amon/forest/ryo3.c");
    obb->set_haunt(this_player()->query_real_name());
    move_object(obb,environment(environment(this_object())));
  }
  flesh_heal = flesh_heal - 1;
  if(flesh_heal < 1) {
  write("The meat is all gone.\n"); 
  destruct(this_object()); }
  return 1;}
}
