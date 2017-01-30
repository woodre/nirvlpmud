#include "/players/fred/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("parachute");
  set_alias("chute");          
  set_short(GRN+"A parachute"+NORM);
  set_long(
  "  A small white parachute used by the paratrooping \n"+
  "squirrels of the "+BOLD+"Crazed Forest"+NORM+".  You are not\n"+
  "sure what to do with it.\n");
  set_type("misc");
  set_ac(1);
  set_weight(1);
  set_value(200);
}
  
