#include "/obj/ansi.h"
/*define PLAN "/open/pub_plans/tallos.plan"
*/
#define PLAN "/players/tallos/PLAN"

void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(PLAN, HIB+"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"+NORM+NORM);
  write_file(PLAN, "Coding: \n7"+HIY+"Tigers Inn"+NORM+".................................80% done   Newbie\n"+HIB+"City of Raven's Bluff"+NORM+".......................10% done   Mid-High\n"+HIG+"The Vast"+NORM+".....................................5% done   Mid-High\n"+HIM+"Castle Dragons Dream"+NORM+".........................1% done   High\n"+NORM+NORM);
  write_file(PLAN, "Guild Concept:"+HIR+" Barbarians"+NORM+NORM+"\n\n");
  write_file(PLAN, HIK+"Ideas: Interesting Sex emotes. Mail ideas to Tallos.\n");
  write_file(PLAN, HIB+"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"+NORM+NORM);
  destruct(this_object());
}