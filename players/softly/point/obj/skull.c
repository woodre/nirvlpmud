#include "/players/softly/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg){

   set_id("skull");
   set_alias("bone");
   set_short("A skull");
   set_long("A well worn skull, perhaps from a pirate.\n");
   set_weight(1);
   set_value(150);
}

