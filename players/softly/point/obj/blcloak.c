#include "/players/softly/closed/ansi.h"

inherit "obj/armor.c";

reset(arg){

   set_name("blood cloak");
   set_alias("cloak");
   set_type("misc");
   set_short(RED+ "Blood red velvet cloak"+ NORM);
   set_long(RED+"Floor length blood red velvet cloak with a hood.\n"+NORM);
   set_ac(2);
   set_weight(1);
   set_value(1500);
}
