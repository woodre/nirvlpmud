#include "/players/softly/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg){

   set_id("silver");
   set_alias("bar");
   set_short("Silver bar");
   set_long("A battered large bar of pure silver.\n");
   set_weight(1);
   set_value(600);
}

