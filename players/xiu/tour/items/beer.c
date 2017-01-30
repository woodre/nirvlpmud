#include "/players/fred/ansi.h";
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
set_name("beer");
add_alias("can");
set_short(BOLD+RED+"A Can of Beer"+NORM);
set_long("A can of lukewarm beer that has a little\n"+
"dirt on the top, but would still be okay to drink.\n");
set_type("drink");
set_msg("You pop open the beer and take a swig\n");
set_msg2(" drinks some beer.\n");
add_cmd("drink");
set_heal(5,5);
set_charges(1);
set_intox(30);
set_value(25);
}

query_save_flag(){
  return 1;
  }
