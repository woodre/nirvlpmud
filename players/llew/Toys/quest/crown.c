#include "/players/llew/closed/ansi.h"
inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("crown");
   set_alias("toy_quest_crown");
   set_short(HIY+"Golden Lego Crown"+NORM);
   set_long("The golden lego crown of the King of the lego people shines\n"+
            "with a metallic luster.\n");
   set_value(200);
   set_weight(1);
}
