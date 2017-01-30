#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "fakir";
  cap_owner = "Fakir";
  color = HIR;
  extra_look = "Fakir's glowing smile warms your heart";
}
