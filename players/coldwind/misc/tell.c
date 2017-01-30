#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "coldwind";
  cap_owner = "Coldwind";
  color = HIB;
  extra_look = "Coldwind is surrounded by icicles";
}
