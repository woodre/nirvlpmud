#include "/players/pestilence/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "pestilence";
  cap_owner = "Pestilence";
  color = RED;
  extra_look = ""+HIK+"Pestilence"+NORM+" has a tattoo of the "+HIR+"Four horseman"+NORM+" on his back";
}

