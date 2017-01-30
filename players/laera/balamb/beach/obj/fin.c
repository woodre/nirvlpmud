#include "/players/laera/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("fish fin");
  set_alias("fin");
  set_short(YEL+"Fish Fin"+OFF);
set_long(
"A fin from a Fastiticalon-F.  It used to be said that if one had the\n" +
"right powers, this fish fin would be useful.  That legend has long \n" +
"discarded and now the fin is of very little use or value.\n");

  set_value(700 + random(250));
  set_weight(3);
}

