/* polish - clone a new copy of the guild object
 */

#include "/players/illarion/guild/def.h"

string help() {
  return "Usage: polish armband\n"+
         "Cost:  none\n\n"+
         "This ability allows you to replace your armband, in the\n"+
         "event that it needs some kind of repair.\n";
}

status main(string arg,object gob,object owner) {
  object newob;
  if(!arg || arg !="gauntlet")
    FAIL("Polish what?\n");
  gob->end_grip();
  gob->save_guild_stats();
  newob=clone_object(GDIR+"object");
  destruct(gob);
  move_object(newob,owner);
  write("Your gauntlet has been replaced.\n");
  return 1;
}
