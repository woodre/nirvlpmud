/* polish - clone a new copy of the guild object
 */

#include "/players/illarion/guild/def.h"

string help() {
  return "Usage: absorb\n"+
         "Cost:  none\n\n"+
         "The power of the gauntlet allows you to absorb the souls of\n"+
         "your foes.  Souls come in different colors depending on\n"+
         "chance and the situation.\n\n"+
         "While absorbing souls you will be unable to attack, and\n"+
         "only your dodge and armor use defensive skills will\n"+
         "function, as you must hold your gauntlet hand still to\n"+
         "absorb the souls.\n\n"+
         "For more information, see ghelp souls.\n";
}

status main(string arg,object gob,object owner) {
  gob->toggle_absorb();
  return 1;
}
