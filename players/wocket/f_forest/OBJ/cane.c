#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon.c";

reset(arg){
  if(arg) return;
  set_id("cane");
  set_short(YEL+"A wooden cane"+OFF);
  set_long("A small wooden cane.  This was old man Palum's cane.\n");
  set_class(12);
  set_weight(2);
  set_value(75);
}
