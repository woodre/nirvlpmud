/*Erethor: eres1.c
 *Wizard:  Mishtar
 *Created: 1/13/04
 *Edited:  5/19/04
 *Realm:   Erethor
 */

#include <ansi.h>
#include "/players/mishtar/defs.h"
inherit "players/vertebraker/closed/std/room.c";

/* Global Variables */
string *Names; /* Names of the players who have tasted this soup */

int tasted;

reset (int arg)
{
    /* Whether it's a reset or creation, clear the array */
    Names = ({ });

    if (arg)
      return;

	set_light(1);
	set_short(GRN+"An elven residence"+NORM);
	set_long(GRN+"An elven residence"+NORM+" [west]\n"+
		"The small oaken door opens up into this cozy little abode. \n"+
		"The small fire in a stone fireplace licks at the bottom of a \n"+
		"stew pot as it cooks slowly.  The pleasant aroma of the soup \n"+
		"within floats about the room and melds with the scent of the \n"+
		"pies cooling on the window sill.  Soft silken tapestries hang \n"+
		"on the walls for added warmth during the cool nights as well \n"+
		"as add a decorative feel to the home.\n");
		
	add_item("fire",
			 "The small golden fire crackles and hisses as it dances in \n"+
			 "the stone fireplace");
	add_item("fireplace",
			 "A smooth stoned fireplace sits tucked in the back wall of \n"+
			 "the house providing limited warmth and some light");
	add_item("pot",
			 "A finely made iron pot hangs over the fire slowly simmering \n"+
			 "a chicken and vegetable stew");
	add_item("pies",
			 "A pair of fresh, golden brown pies sit cooling on the sill");
	add_item("tapestries",
			 "The tapestries are made of fine silk of different colors. \n"+
			 "Each one depicts a different scene of elven life");

	add_smell("soup",
			  "The delicious aroma of slowly simmering chicken and fresh \n"+
			  "cut vegetables floats around the pot.");
	add_smell("pies",
			  "The delightful scent of warm berries wafts from the pies \n"+
			  "on the windowsill.");

	add_listen("main",
			   "The whispered crackle of the fire and a soft gurgling of the \n"+
			   "boiling stew compete with the cacauphony of noises floating \n"+
			   "in from the window.");
	
	add_exit("/players/mishtar/areas/erethor/room/eroad1.c","west");
	add_exit_msg("west", ({"You leave the residence.\n","leaves the residence.\n"}));

	tasted = 0;
}

init()
{
	::init();
		add_action("taste_soup","taste");
}

/*Soup Heal*/
taste_soup(str)
{
    string name;

    name = (string)this_player()->query_real_name();

	if(!str)
   { 
	  write("Taste what?\n");
	  return 1;
   }

    if (str != "soup")
    {
      notify_fail("The only thing here you can taste is the soup.\n");
      return 0;
    }

    /*
     * Check if there are any entries in Names, if so, 
     * Check if name is a member of Names, if so
     * then tell them hell no
     */
    if (sizeof(Names) && member_array(name, Names) >= 0)
    {
      notify_fail("Hey don't be so greedy!\nYou've already had some hoser!\n");
      return 0;
    }
else
{
Names += ({ name }); /* Add them to the array */
		if(!call_other(TP,"eat_food",25))
{		tasted = 0;
		return 1;
}
		else
{ 
			write("You take a taste of the simmering stew, Yum!\n");
			say(TPN+" takes a taste of the simmering stew.\n");
			call_other(TP,"heal_self",50);
			tasted = 1;
			return 1;
}
}
	else if(tasted != 0)
{
		write("You take a taste of the simmering stew, Yum!\n");
		say(TPN+" takes a taste of the simmering stew.\n");
		return 1;
}
}
