#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "jareel";
  cap_owner = "Jareel";
  color = RED;
  extra_look = "Jareel fists are soaked in the purifying blood of others";
}
