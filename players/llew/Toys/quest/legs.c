#include "/players/llew/closed/ansi.h"
inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("legs");
   set_alias("toy_quest_legs");
   set_short(HIR+"Red Lego Legs"+NORM);
   set_long("The red legs of the King of the lego people.  They wiggle nicely\n"+
            "back and forth.  If the rest of the body were here it would make\n"+
            "for a very handsome lego person.\n");
   set_value(200);
   set_weight(1);
}
