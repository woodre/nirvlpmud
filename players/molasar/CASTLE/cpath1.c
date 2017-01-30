#include "std.h"
#define MOLGUARD 1

int count, i;

#if MOLGUARD
object molguard, armor, shield, sword;
#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!find_living("molguard"))\
        starta_molguard();
#endif

TWO_EXIT("players/molasar/CASTLE/entrance","east",
         "players/molasar/CASTLE/cpath2","west",
         "A path to the castle",
 "A path that leads to the entrance of the inner castle.  The exit of\n"+
 "the castle's compound lies to the east.\n",1)

#if MOLGUARD
starta_molguard() {
    i = 0;
    if(!molguard || !living(molguard)) {
      while(i<3) {
      i += 1;
        molguard = clone_object("players/molasar/MONSTERS/guard");
        armor = clone_object("players/molasar/ARMOR/leather_armor");
        shield = clone_object("players/molasar/ARMOR/shield");
        sword = clone_object("players/molasar/WEAPONS/sword");
        transfer(armor, molguard);
        transfer(shield, molguard);
        transfer(sword, molguard);
        call_other(molguard, "init_command", "wear leather armor");
        call_other(molguard, "init_command", "wear shield");
        call_other(molguard, "init_command", "wield sword");
	move_object(molguard, "players/molasar/CASTLE/cpath1");
      }
    }
}
#endif

