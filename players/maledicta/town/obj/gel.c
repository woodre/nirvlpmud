#include "/players/maledicta/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("gel");
  add_alias("tube");
  add_alias("medicinal gel");
  add_alias("blue medicinal gel");
  set_short(BLU+"blue medicinal gel" + NORM);
  set_long("\
This is a small tube of medical squeeze gel.  It\n\
is a very potent medicine that is used to restore\n\
the body's energy.  You can 'gulp gel' to use it.\n");
  set_type("gulps");
  set_msg("You grab a tube of medicinal gel and squeeze it into your mouth.\n\
A powerful surge runs through your body.\n");
  set_msg2(" gulps some gel.\n");
  add_cmd("gulp");
  set_heal(0,50);
  set_charges(3);
  set_soak(10);
  set_stuff(10);
  set_value(250);
  set_msg_soaked(HIR+"You are too soaked to use it!"+NORM);
  set_msg_stuffed(HIR+"You are too stuffed to use it!"+NORM);
  set_msg_precharges(BOLD+"["+NORM+BLU);
  set_msg_postcharges(NORM+BOLD+"]"+NORM);
  set_type_single("gulp"); /* verte */
}
query_save_flag(){
  return 1;
  }
