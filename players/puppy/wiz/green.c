#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "puppy";
  cap_owner = "Puppy";
  color = BOLD+HIG;
}

