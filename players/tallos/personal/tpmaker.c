#include "/obj/ansi.h"
/*define PLAN "/open/pub_plans/tallos.plan"
*/
#define PLAN "/players/tallos/PLAN"

void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(PLAN, HIB+"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"+NORM+NORM);
  write_file(PLAN, "Coding: \n7Tigers Inn...................80% done   Newbie\nCity of Raven's Bluff...................10% done   Mid-High\nThe Vast...................5% done   Mid-High\nCastle Dragons Dream...................1% done   High\n"+NORM+NORM);
  write_file(PLAN, "Guild Concept:"+HIR+" Barbarians"+NORM+NORM+"\n\n");
  write_file(PLAN, HIK+"Ideas: Interesting Sex emotes. Mail ideas to Tallos.\n");
  write_file(PLAN, HIB+"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"+NORM+NORM);
  destruct(this_object());
}
