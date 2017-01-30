#include "/obj/ansi.h"

#define pub_plans "/open/pub_plans/tallos.plan"

void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(pub_plans, HIB+"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"+NORM+NORM);
  write_file(pub_plans, "Coding: \n7"+HIY+"Tigers Inn"+NORM+"................................100% done   All\n"+HIB+"City of Raven's Bluff"+NORM+".......................20% done   Mid-High\n"+HIG+"The Vast"+NORM+"....................................10% done   Mid-High\n"+HIM+"Castle Dragons Dream"+NORM+".........................5% done   High\n"+NORM+NORM);
  write_file(pub_plans, "Guild Concept:"+HIR+" Sailor Scouts"+NORM+NORM+"\n\n");
  write_file(pub_plans, HIK+"Ideas: Interesting Sex emotes. Mail ideas to Tallos.\n");
  write_file(pub_plans, HIB+"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"+NORM+NORM);
  destruct(this_object());
}
