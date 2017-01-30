#include <ansi.h>
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "skie";
  cap_owner = "Skie";
  color = YEL;
  extra_look = "Skie gonna bus' a cap in yo' ass";
}

