#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "humble";
  cap_owner = "Lexi";
  color = CYN;
  extra_look = "Lexi has a small "+HIM+"heart"+OFF+" tattoo on her left shoulder blade";
}
