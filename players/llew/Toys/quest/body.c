#include "/players/llew/closed/ansi.h"

inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("body");
   set_alias("toy_quest_body");
   set_short(RED+"Purple Lego Body"+NORM);
   set_long("The yellow lego body is dressed in a royal purple robe\n"+
      "with white trim running its length.  It looks like it might be\n"+
      "worth something... to a legoman.\n");
   set_value(200);
   set_weight(1);
}
