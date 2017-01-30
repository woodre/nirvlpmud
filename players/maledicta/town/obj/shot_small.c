#include "/players/maledicta/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("shot");
  add_alias("bloodcleanser");
  add_alias("bloodcleansing shot");
  set_long("\
A shot of bloodcleansing liquid.  It will immediately take some\n\
of the alcohol from the user's bloodstream.  You can 'inject'\n\
the shot.\n");
  set_short("Bloodcleansing shot");
  set_msg("\
You inject yourself with a shot of blood cleansing fluid.\n\
Instant relief floods into your body.\n\
You crush it and drop the fragments to the ground.\n");
  set_msg2(" injects something into an arm.\n");
  add_cmd("inject");
  set_heal(0,0);
  set_charges(1);
  set_intox(-15);
  set_value(300);
  set_msg_precharges(HIG+"[");
  set_msg_postcharges("]"+NORM);
  set_type_single("injection"); /* verte */
}
