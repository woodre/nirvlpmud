#include "/players/snakespear/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
set_id("hematite");
set_alias("qpiece2");
set_short("a "+GRY+"silvery "+NORM+"piece of hematite");
set_long(
  "  This is a piece of magical hematite.  It is heavy, solid and\n"+
  "silvery black.  It's name alone is a mystery.  This stone is\n"+
  "known for it's magical healing powers.  The stone has been thought\n"+
  "to heal itself.  The hematite only looks valueable to you though.\n");
set_weight(2);
set_value(300);
}
