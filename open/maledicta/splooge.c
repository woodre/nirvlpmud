#include "/players/fred/ansi.h";
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("splooge");
  add_alias("tube");
  set_short(BOLD+BLK+"["+HIR+"Splooge"+BLK+"]"+NORM);
  set_long("A tube filled with a liquidy ooze.\n"+
           "You are not quite sure what it is but\n"+
           "you have the urge to 'squeeze' it.\n");
  set_type("drink");
  set_msg("You hold the tube to your mouth and squeeze it lightly.\n"+
          "Some of the liquid shoots into your mouth.  MMMmm!\n");
  set_msg2(" squeezes some of the splooge into their mouth.\n");
  add_cmd("squeeze");
  set_heal(50,50);
  set_charges(3);
  set_soak(7);
  set_stuff(7);
  set_value(600);
}

query_save_flag(){
  return 1;
  }
