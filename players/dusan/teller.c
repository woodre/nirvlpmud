#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "dusan";
  cap_owner = "Dusan";
  color = HIR;
  extra_look = "";
}
