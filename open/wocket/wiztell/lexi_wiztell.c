#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "lexi";
  cap_owner = "Lexi";
  color = HIM;
  extra_look = "Lexi has a small "+HIM+"heart"+OFF+" tattoo on her left shoulder blade";
}
