#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "tristian";
  cap_owner = "Tristian";
  color = BOLD+HIB;
}

