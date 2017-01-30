#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/gendrink.c";

reset(arg){
  if(arg) return;
set_name("flesh");
set_short(HIY+"some sponge flesh"+NORM);
set_long("This is the pale yellow flesh of a cave sponge.  You might want to 'eat' it\n"+
   "to regain some health.\n");
set_cmd("eat");
set_alias("sponge");
set_strength(8);
set_heal(50);
set_charges(3);
set_cost(16);
set_type("eat_food");
set_destruct_msg2("You finish off the rest of the sponge flesh.\n");
set_destruct_msg1("eats all of the sponge flesh.\n");
set_empty_container("destructme");
}
