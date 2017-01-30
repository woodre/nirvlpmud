#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "katya";
  cap_owner = "Katya";
  color = HIM;
  extra_look = "Katya has a twinkle in her eye";
}

