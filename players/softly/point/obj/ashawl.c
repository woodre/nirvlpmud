#include "/players/softly/closed/ansi.h"

inherit "obj/armor.c";

reset(arg){

   set_name("blue shawl");
   set_alias("shawl");
   set_type("misc");
   set_short(BLU + "A deep blue shawl" + NORM);
   set_long("A large deep blue knitted shawl, made with loving hands.\n");
   set_ac(1);
   set_weight(1);
   set_value(600);
}
