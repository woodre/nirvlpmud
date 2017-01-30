/* 
 * Forbin
 * Created:   2003.08.21
 * Last edit: 2003.08.21 -forbin
 */

#include "/players/forbin/define.h"
inherit "/obj/treasure";
#define ROOT "/players/snow/dervish/trials/trail1/"

id(str) { return (::id(str) || str == "pillar" || str == "pillars"
                            || str == "pillars of darkhune"
                            || str == "pillars of dar'khune"
                            || str == "the pillars of darkhune" 
                            || str == "the pillars of dar'khune"); }

reset(arg) {
  if(arg) return;
   
  set_short(HIK+"The Pillars of Dar"+HIW+"'"+HIK+"Khune"+NORM);
  set_long("  Four black obelisks tower high into the sky above.  Each three sided\n"+ 
           "pillar rises straight up almost 60 feet before tapering to a point.\n"+  
           "Bright white symbols are etched into the surface of every one, and\n"+ 
           "each pillar is cloaked in a cracking energy that creeps over them.\n");
  set_weight(1000000);
  call_out("energy_crackle",5+random(5));
}

init() {
  ::init();
  add_action("cmd_look","look");
  add_action("cmd_read","read");
}

cmd_look(string str) {
}

cmd_read(string str) {
}

energy_crackle() {
  if(random(3)) { tell_room(environment(),"Energy crackles and pops all about the pillars.\n");
  else tell_room(environment(),"The air around the pillars is seared with energy.\n);
  call_out("energy_crackle",5+random(20));
}

