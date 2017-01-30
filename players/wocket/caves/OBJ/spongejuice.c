#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/gendrink.c";

reset(arg){
  if(arg) return;
set_name("juice");
set_short(HIB+"some sponge juice"+NORM);
set_long("This is the blue gooey vital fluid of a cave sponge.  You might\n"+
         "want to 'drink' it to regain some health.\n");
set_cmd("drink");
set_alias("sponge");
set_strength(6);
set_heal(50);
set_charges(3);
set_cost(16);
set_type("drink_soft");
set_destruct_msg1("drinks all of the sponge juice.\n");
set_destruct_msg2("You drink the last bit of sponge juice.\n");
set_empty_container("destructme");
}

is_heal(){ return 1; }
