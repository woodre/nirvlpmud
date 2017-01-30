/*
 * Shardak guild - (tm) Dragnar/John
 * Rock is (c) Balowski/Rasmus, January 30th 1995.
 * Last change: Feb 19th '95
 * Because the entrance to the guild can be placed at an arbitrary location,
 * an object is most adequate for the purpose. Cloned in castle or init_file?
 * Just load the object and have DEST defined to put entrance on the grid
 */
#pragma strict_types
#include "../def.h"
inherit "obj/clean";

void
reset(int arg)
{
    if (arg)
	return;
    set_no_clean(1);            /* should always keep the entrance? */
	move_object(this_object(), DEST);
}

status
id(string str)
{
    return(str == "rock" || str == "formation" || str == "opening" || str == "cave");
}

string
short()
{
    return "A rock formation";
}

void
long(string str)
{
    if (str == "opening")
	write( "\
The opening is smoothly carved into the rock, providing an entrance to\n\
a cave inside the rock. Along the rim of the opening runes have carefully\n\
been cut. The inside is too dark to make out standing in the sunlight, but\n\
as you listen carefully, you can hear something resembling voices emanating\n\
from the cave.\n"); 
    else
	write( "\
Like a tip of an iceberg the moss-grown rock sticks up from the earth.\n\
A thick stone door lies on the ground in front of an opening carved into\n\
the rock. The door, sooted and broken in two, must have been flung from\n\
the opening. Cold air is gushing out from the inside of the rock, making\n\
you shiver a little.\n");
}

void
init()
{
    add_action( "enter", "enter");
}

status
enter(string str)
{
    string gname;
    gname = (string)this_player()->query_real_name();
    if(!id(str)) {
	notify_fail( "Enter what?\n");
	return 0;
    }

    /* only let players below neutral enter */
    gname = (string)this_player()->query_real_name();
/*
    if(this_player()->is_player() && this_player()->query_level() < 21)
    if(member_array(gname, TESTERS) == -1) 
    {
      write("You may not enter yet.\n");
      return 1;
    }
 */
/*
    if ((this_player()->query_alignment() > -40) && !this_player()->query_ghost())
	write( "You decide not to enter the lair of evil.\n");
    else
*/
	this_player()->move_player( "into cave#" + PATH + "cave");
    return 1;
}
