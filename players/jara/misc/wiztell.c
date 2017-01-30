#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "jara";
  cap_owner = "Jara";
  color  = GRN;
}
