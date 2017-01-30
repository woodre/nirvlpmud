#include "/players/llew/closed/ansi.h"

inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("arm");
   set_alias("toy_quest_arm");
   set_short(HIY+"Yellow Lego Arm"+NORM);
   set_long("The yellow lego arm of the King of the lego people.\n"+
      "He couldn't rule with a yellow fist without it.\n");
   set_value(5);
   set_weight(1);
}
