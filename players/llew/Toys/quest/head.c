#include "/players/llew/closed/ansi.h"

inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("head");
   set_alias("toy_quest_head");
   set_short(HIY+"Yellow Lego Head"+NORM);
   set_long("The smiling yellow face looks to be very noble,\n"+
         "as if it may belong to someone very important.\n");
   set_value(100);
   set_weight(1);
}
