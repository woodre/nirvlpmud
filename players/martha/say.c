#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
owner = "martha";
cap_owner = "Martha";
color = BOLD+HIB;
}

