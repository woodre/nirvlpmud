#include "/players/softly/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg){

   set_id("nugget");
   set_alias("gold");
   set_short(YEL+"Gold nugget"+NORM);
   set_long("A small irregularly shaped gold nugget.\n");
   set_weight(1);
   set_value(150+random(150));
}

