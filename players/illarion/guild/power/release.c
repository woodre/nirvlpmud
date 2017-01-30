/* release.c - manually ends the use of guild skills
 *
 */

#include "/players/illarion/guild/def.h"

string help() {
  return "Usage: release\n"+
         "Cost:  none\n\n"+
         "When you're finished using a weapon in the two-handed\n"+
         "style, you can release your grip and go back to using\n"+
         "it normally.\n";
}

status main(string arg,object gob,object owner) {
  if(!gob->check_weapon())
    FAIL("You are not using a two-handed grip.\n");
  gob->set_weapon(0);
  gob->check_weapon();
  DAEM->do_skill_spam("grip",gob,owner,0,0);
  return 1;
}

