#include "/players/balowski/lib.h"
inherit PORTHEAL;

void
create()
{
    ::create();
    set_name("bottle");
    set_charge_name("shot", "shots");
    set_verb("drink");
    set_short("A bottle of Fire Water");
    set_long("\
In the middle ages, fear and magic ruled the land.  Against a backdrop\n\
of marauding barbarians, alchemists were on an endless quest to find\n\
the Elixir of Life.  According to the legend, this potion would cure\n\
all ailments and lengthen life.  Their powerful magic drink is said to\n\
have caused water to burn and man to breathe fire.  Although no one\n\
knows whether life was lengthened, many claimed to have seen visions\n\
of flame breathing dragons.  They called their potion Fire Water.\n");
    set_messages(
	"You see a vision of a dragon breathing flames.\n",
	" slams a shot of Fire Water.\n" +
	"You have a sudden fear of flame breathing dragons.\n");
    /*set_empty_message(
	"You smash the bottle on the ground as you finish the firewater.\n");*/
    set_charges(7);
    set_intox(12);
    set_heal(16);
}
