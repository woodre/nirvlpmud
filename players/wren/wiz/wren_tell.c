#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "wren";
  cap_owner = "Wren";
  color = YEL;
  extra_look = "Wren is spiffy";
}

