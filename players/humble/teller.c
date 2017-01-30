#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
owner = "humble";
cap_owner = "Humble";
color = HIC;
extra_look = "Humble appears to be riding on a "+HIB+"Giant"+OFF+" "+HIC+"Winged"+OFF+" "+HIY+"MOO COW"+OFF+" "+HIR+"{BeLiGeRiNt}"+OFF+" ";
}
