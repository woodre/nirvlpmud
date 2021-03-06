#include "/players/mythos/closed/guild/def.h"

id(str) { return (str == "worm" || str == "maggot"); }
prevent_insert(){ write("The worm wriggles free before it can be bagged.\n"); return 1; }

reset(arg) {
if(arg) return;
  call_out("eat",3);
}

long(){
  write("A small white worm- a maggot.\n"+
        "Disgusting little thing, it eats its way\n"+
        "through its host and plants eggs in the corpse.\n"+
        "You feel that you should squash it...\n");
}

short() { return "worm"; }

drop(){ return 1; }
get(){ return 0; }
can_put_and_get(){ return 0; }
query_weight() { return 1; }
query_value() { return 0; }
query_save_flag() {return 1;}

init(){
  if(this_player()) if(this_player()->query_dmon()) { destruct(this_object()); return 1; }
  if(this_player()) if(this_player()->query_real_name() == "guest") { destruct(this_object()); return 1; }
  add_action("sqill","squash");
}

sqill(str) {
if(!str) return 0;
  if(str == "worm" || str == "maggot") {
  write("You squash the worm....\n");
  say(capitalize(tpn)+" squashes a worm.\n");
  destruct(this_object());
  return 1;
  }
return 1;}

eat() {
int m;
object prey;  
if(ep) {
  if(living(ep)) {
  if(ep->query_ghost()) { destruct(this_object()); return; }

  /* Added by Rumplemintz */
  if (!environment(this_object())->query_pl_k()) {
    destruct(this_object());
    return;
  }

  ep->heal_self(-1);
  if(random(10) == 0) {
  tell_object(ep,"Something feels VERY wrong!\n"); }
  move_object(this_object(),ep); }
  else {
  prey = all_inventory(ep);
   for(m=0;m<sizeof(prey);m++) {
    if(living(prey[m]) && !(prey[m]->id("messenger")) && random(3) == 0) {
      move_object(this_object(),prey[m]); 
      call_out("eat",3); return 1;}
      }
  }
  if((ep->query_npc() && random(10) == 0) || (present(fear,ep) && random(3)== 0)) {
  move_object(this_object(),environment(ep));
  if(this_object())
  if(ep)
  tell_room(ep,"A worm drops to the ground.\n");
  } 
  call_out("eat",3); }
return 1;}
