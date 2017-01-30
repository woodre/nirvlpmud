#include "/players/mythos/closed/guild/def.h"
object bear;
int worn;

id(str) { return str == "tiara" || str == "jewel" || str == "darm"  ||
                 str == "jewel of darm"; }
                 
reset(arg) {
  if(arg) return;
  worn = 0;
  call_out("checks",50);
}

query_weight() { return 1;}

query_value() { return 0; }

query_save_flag() { return 1; }

drop() { return 0;}
get() { return 1;}

short() { return "A black Tiara"; }

long() {  write("You feel a deep foreboding as you examine\n"+
                "this tiara.  A dark purple jewel is set into\n"+
                "the center of this headpiece.  There are strange\n"+
                "markings along the edge of the tiara.\n");
        }
       
init() { 
  add_action("read","read");
  add_action("wwear","wear");
  add_action("rremove","remove");
  add_action("ddrop","drop");
  add_action("invoke","invoke");
}

read(str) {
  if(!str) return 0;
  if(str == "tiara" || str == "jewel" || str == "darm") {
    write("The Jewel of Darm.  Wear me and know fear....\n"+
          "For I am the Legendary Jewel....\n");
  return 1;}
}

checks() {
if(worn) {
  if(living(ep)) {
  if(!present(pact,ep) && !(ep->query_npc())) {
    tell_object(ep,"You feel dizzy.\nSomething drains your lifeforce.\n");
      ep->add_hit_point(-1-random(3));
        if(random(3) ==0) { ep->lower_attrib(); }
        ep->reset(1);
        ep->save_me();
    tell_room(environment(ep),capitalize(ep->query_real_name())+
              " faints.\n");
  }
  if(present(pact,ep)) {
    present(pact,ep)->add_sacrifice(10+random(100));
    tell_object(ep,"You sense something dark seep into your soul.\n");
  }
  } 
  worn = 0;}
  call_out("checks",25+random(50));
return 1;}

ddrop(str) { 
  if(!str) return 0;
  if(str == "tiara" || str == "jewel" || str == "darm") {
    if(ep == this_player()) {
     worn = 0; } 
   }
}

wwear(str) { 
  if(!str) return 0;
  if(str == "tiara" || str == "jewel" || str == "darm") {
    if(ep == this_player()) {
       worn = 1;
       write("You wear the Tiara!\nSomething invades your soul.....\n");
       say(capitalize(tpn)+" wears the Tiara.\n"+
          "A black aura descends upon "+capitalize(tpn)+". \n");
    return 1; }
   }
 }
 
 rremove(str) {
   if(!str) return 0;
  if(str == "tiara" || str == "jewel" || str == "darm") {
    if(ep == this_player()) {
       worn = 0;
       write("You remove the Tiara.\n");
       say(capitalize(tpn)+" removes the Tiara.\n");
    return 1; }
   }
 }

invoke() {
  if(!present(fear,tp) || !worn) return 0;
  if(tgl != 3 || tl < 8 || qtf < 4)  return 0;
  write("You feel a small burst of energy run through you.\n");
  say(capitalize(tpn)+" screams!\nDarkness shrouds the room and death is in the air!\n");
  bear = tp;
  write("You feel dizzy and fall to the ground.\n");
 move_object(clone_object("/players/mythos/closed/guild/task/4/still.c"),tp);
  call_out("invoke2",6);
return 1;}

invoke2() {
  tell_object(bear,"Pain wracks your body and you can not move!\n");
  bear->add_hit_point(-15);
  call_out("invoke3",10);
return 1;}

invoke3(){
  tell_object(bear,"A small voice- childlike- calls to you....\n");
  call_out("invoke4",15);
return 1;}

invoke4() {
  tell_object(bear,"The childlike voice tells you:  I'm hungry...Grant me food....\n");
call_out("invoke5",10+random(7));
return 1;}


doner() {
tell_object(bear,"Something dark floods you!\n");
  present(fear,bear)->set_dark_level(4);
  present(fear,bear)->add_sacrifice(10);
  present(fear,bear)->dsave();
  present(fear,bear)->update_me();
destruct(this_object());
return 1;}
