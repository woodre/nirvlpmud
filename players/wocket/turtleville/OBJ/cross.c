#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
set_id("cross");
set_short(BOLD+"A silver cross"+NORM);
set_long("A plain pure silver cross that shines in the light.  Even though its\n"+
          "not very ornate it still looks expensive.\n");
set_weight(2);
set_value(1000+random(500));
}