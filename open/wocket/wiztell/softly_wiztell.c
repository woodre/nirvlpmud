#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "softly";
  cap_owner = "Softly";
  color = HIB;
  extra_look = "Softly looks mighty soft";
}
