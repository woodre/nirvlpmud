#include "/players/feldegast/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "catacomb";
  cap_owner = "Catacomb";
  color = HIR;
  extra_look = "Catacomb looks quite wizardly";
}
