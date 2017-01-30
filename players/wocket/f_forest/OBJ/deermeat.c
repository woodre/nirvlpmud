#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/gendrink.c";

reset(arg){
  if(arg) return;
  set_name("meat");
  set_alt_name("deer meat");
  set_short("A chunk of deer meat");
  set_long("This is a chunk of deer meat.  You might want to 'eat' some\n"+
           "of it to regain some health.\n");
  set_cmd("eat");
  set_charges(3);
  set_strength(12);
  set_heal(45);
  set_type("eat_food");
  set_destruct_msg1("eats all of the deer meat.\n");
  set_destruct_msg2("You finish off the rest of the deer meat.\n");;
  set_empty_container("destructme");
}
