#include "/players/maledicta/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("injector");
  add_alias("green");
  add_alias("green injector");
  set_short("Injector "+GRN+"]GREEN["+NORM+"");
  set_long("  This is a small metallic injector used for healing\n"+
           "major wounds.  To use type: inject green\n");
  set_type("uses");
  set_msg("You pick up an injector and place it against your arm. You press the\n"+
"button and feel a soothing chemical enter your bloodstream.\n");
  set_msg2(" uses an injector.\n");
  add_cmd("inject");
  set_heal(50,50);
  set_charges(3);
  set_soak(10);
  set_stuff(10);
  set_value(300);
  set_msg_soaked(HIR+"You are too soaked to use it!"+NORM);
  set_msg_stuffed(HIR+"You are too stuffed to use it!"+NORM);
  set_msg_precharges("");
  set_msg_postcharges("");
  set_type_single("use"); /* verte */
}

query_save_flag(){
  return 1;
  }
