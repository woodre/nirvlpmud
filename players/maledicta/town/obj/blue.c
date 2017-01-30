#include "/players/maledicta/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("injector");
  add_alias("blue");
  add_alias("blue injector");
  set_short("Injector "+BLU+"]BLUE["+NORM+"");
  set_long("  This is a small metallic injector used for healing\n"+
           "major wounds.  To use type: inject blue\n");
  set_type("uses");
  set_msg("You pick up an injector and place it against your arm. You press the\n"+
"button and feel a soothing chemical enter your bloodstream.\n");
  set_msg2(" uses an injector.\n");
  add_cmd("inject");
  set_heal(50,50);
  set_charges(15);
  set_soak(7);
  set_stuff(7);
  set_value(650);
  set_msg_soaked(HIR+"You are too soaked to use it!"+NORM);
  set_msg_stuffed(HIR+"You are too stuffed to use it!"+NORM);
  set_msg_precharges("");
  set_msg_postcharges("");
  set_type_single("use"); /* verte */
}

int query_weight()
{
  switch(charges)
  {
    case 14..2000: return 5;
    case 11..13: return 4;
    case 8..10: return 3;
    case 5..7: return 2;
    default: return 1;
  }
}
query_save_flag(){
  return 1;
  }
