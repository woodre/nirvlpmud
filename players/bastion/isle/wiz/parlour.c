
#include "std.h"

#undef EXTRA_LONG
#define EXTRA_LONG \
     if(str=="magazine" || str=="magazines") { \
          write("You see severall issues of 'Eldritch Wizardry,' 'The "+ \
             "Sorcerer's\nScroll,' and 'The UNESCO Courier.'\n"); \
          return; }

/*
extra_long(str) {
     if(str=="magazine" || str=="magazines") {
          write("You see several issues 'Eldritch Wizardry,' 'The Sorcerer's"+
              "\nScroll,' and 'The UNESCO Courier.'\n");
          return; }
}
*/


TWO_EXIT("players/bastion/isle/wiz/w_hall2", "north",
     "players/bastion/isle/wiz/great_hall", "west",
     "Parlour",
     "You enter an elegantly panelled room, the floor lush blue pile, the\n"+
     "furniture made with attention to comfort and intricacy. Blue silk\n"+
     "hangs on the walls above the mahogany wainscotting, while the\n"+
     "ceiling's plasterwork boasts several nymphs, elves and similar\n"+
     "figures. A low table sits between the several chairs, supporting a\n"+
     "tea service and scholarly magazines.\n",
     1)

id(str) { return str=="magazines" || str =="magazine"; }
