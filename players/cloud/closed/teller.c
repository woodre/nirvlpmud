#include "/obj/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "cloud";
  cap_owner = "Cloud";
  color = HIW;
  extra_look = "Cloud is the other white meat";
}
