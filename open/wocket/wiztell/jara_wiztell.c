#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "jara";
  cap_owner = "Jara";
  color  = HIB;
  extra_look = "Jara's supple form seems to entice you";
}
