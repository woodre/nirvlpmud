#include "/players/maledicta/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("injector");
  add_alias("yellow");
  add_alias("yellow injector");
  set_short("Injector "+YEL+"]YELLOW["+NORM+"");
  set_long("  This is a small metallic injector used for healing\n"+
           "lesser wounds.  To use type: inject yellow\n");
  set_type("uses");
  set_msg("You pick up an injector and place it against your arm. You press the\n"+
"button and feel a soothing chemical enter your bloodstream.\n");
  set_msg2(" uses an injector.\n");
  add_cmd("inject");
  set_heal(30,30);
  set_charges(3);
  set_soak(6);
  set_stuff(6);
  set_value(240);
  set_msg_soaked(HIR+"You are too soaked to use it!"+NORM);
  set_msg_stuffed(HIR+"You are too stuffed to use it!"+NORM);
  set_msg_precharges("");
  set_msg_postcharges("");
  set_type_single("use"); /* verte */
}

query_save_flag(){
  return 1;
  }
