/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   1/4/01            */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"     /*area header */

inherit "room/room";

int rnd, i;

reset(arg) {
rnd = random(2);
	if(!present("human", this_object())) {
	  for(i=0; i < rnd; i++) {
	    human = CO(SPNPC+"human.c");
	    MO(human, TO);
	  }
	}
  if(!arg) {

object peter;

set_light(1);

short_desc = HIW+"Perfect"+NORM+" \
"+HIB+"P"+NORM+"e"+HIB+"t"+NORM+"e"+HIB+"r"+NORM+"'s";
long_desc =
  "  "+HIW+"Perfect"+NORM+" "+HIB+"P"+NORM+"e"+HIB+"t"+NORM+"e"+HIB+"r"+NORM+"\
's "+HIG+"P"+HIR+"a"+HIC+"r"+HIM+"a"+HIY+"p"+HIW+"h"+HIB+"e"+HIG+"r"+HIR+"n\
"+HIC+"a"+HIM+"l"+HIY+"i"+HIW+"a\n\
"+BOLD+RED+"WELCOME TO PERFECT PETE'S!!!!"+NORM+" Here you can find a \
veritable \nvariety of various contrivances and an ultimately unreal, union \
of \nunction that Perfect Pete think's you need to own. Pete boasts that the \n\
most touted of tourists come to get their treasury of timely things. Shelf \n\
after of shelf present a plethora of Perfect Pete's penultimate products. A \n\
large sign rests at the end of one of the shelves.\n";

items = ({
  "contrivances",
  "These are somewhat dubious devices",
  "unction",
  "Large, indescribable pieces of usually useless junk",
  "tourists",
  "These are people just like yourselves, about to make the greatest mistake \n\
by buying something here.\n",
  "things",
  "Items that defy the imagination. Pressure-suit patches, camel-shaped \n\
satchels, cameo cameras, blast-proof bottles, and something etherial that \n\
is labeled \'Wraith Steaks\'",
  "shelf",
  "Impossiblly, it seems there are hundreds of shelves, but that can't be \n\
right given the small size of this room",
  "shelves",
  "The shelves are full of things that you may or may not need",
  "products",
  "You see some of the oddest looking products like, ear reduction cream, \n\
heated contact lenses, and a bass boat buffer",
  "sign",
  "                   The sign reads:\n\
You touch it, you buy it. Your finger prints are registered as a sale.\n\
For a detailed menu of what you can \'touch\', read the sign"
});

dest_dir = ({
    SPROOM+"swconcourse.c","west",
  });

/*   if(!peter) { */
/*      peter = CO(SPNPC+"peter.c"); */
/*      MO(peter, TO); */
/*   } */
  }
}

init() {
  ::init();
  add_action("search_me","search");
  add_action("touch_to_buy","touch");
  add_action("read_sign","read");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else switch(str) {
    case "shelves":
    case "shelf": write("You find a small sign.\n"); break;
    case "sign"  : write("You cannot search the sign, perhaps you could \
\'read\' it?\n"); break;
    case "products"  : write("You had better not search through the products \
unless you want to buy them.\n"); break;
    case "items"  : write("You had better not search through the products \
unless you want to buy them.\n"); break;
    case "things"  : write("You had better not search through the products \
unless you want to buy them.\n"); break;
    case "paraphernalia"  : write("You had better not search through the \
products unless you want to buy \nthem.\n"); break;
    default :       write("You furiously search the "+str+" and come up \
empty handed.\n");
  }
  return 1;
}

touch_to_buy(str) {
  if(!str) {
    notify_fail("What are you trying to touch?\n");
    return 0;
  }
  else if(str) {
    write("Unfortunately Pete is having a bit of inventory supply \
problems. \nPlease check back later.\n");
    }
  return 1;
}

read_sign(str) {
  if(!str) {
    notify_fail("So do you know what it is you are trying to do here? \
Perhaps you need to actually read the sign?\n");
    return 0;
  }
  else if(str == "sign") {
    write(HIW+"Perfect"+NORM+" \
"+HIB+"P"+NORM+"e"+HIB+"t"+NORM+"e"+HIB+"r"+NORM+"'s.\n");
    write(read_file( SPSAVE+"pppsign.txt"));
  }
  return 1;
}