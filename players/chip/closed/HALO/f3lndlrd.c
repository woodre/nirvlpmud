      /*                                                                    
       *    File: /players/chip/room/apartment/f3lndlrd.c                
       *    Function: room
       *    Author(s): Chip@Nirvana       
       *    Copyright: Copyright (c) 2008 Chip      
       *               All Rights Reserved   
       *    Source: 5/31/08           
       *    Notes:                                                          
       *                                                                    
       *                                                                    
       *    Change History:                                                 
       */
#include <ansi.h>
inherit "/room/room";

reset(arg)
{
::reset(arg);

if(arg) return;

set_light(1);

short_desc = ""+HIW+"The "+HIB+"Landlord's "+HIW+"Suite"+NORM+"";

long_desc =
	"This room definately used to be the landlord's dwelling. It seems\n"+
	"as though even after so many years of being unkempt, it is still\n"+
	"in a very slightly better condition than the other apartments\n"+
	"were when they were still being lived in. There is a misshapen\n"+
	"closet on the far west wall, and an old Xbox still hooked up to\n"+
        "an old Zenith CRT style TV set.\n";

add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
add_smell("urine", "The scent is strong and makes it difficult to breathe properly");

move_object(clone_object("/players/chip/mobs/apartment/felon2.c"));

items =
({
	"walls",
	"They are all covered in filth and peppered with holes of many sizes",
	"floor",
	"There is lots of trash, dirt, and chunks of drywall",
	"ceiling",
	"It is very moldy and some of it is hanging loosely, ready to fall as the rest of it already has",
	"dirt",
	"It is everywhere",
	"dust",
	"It covers almost everything",
	"mold",
	"It is growing in many large spots, due to trapped moisture and humidity",
	"mildew",
	"It is growing in many large spots, due to trapped moisture and humidity",
	"holes",
	"Holes litter the walls and ceiling, which explains the debris cluttering the floor",
	"trash",
	"Empty beer cans and shreds of newspaper are amongst the rest of the garbage",
	"drywall",
	"There are chunks of it laying around everywhere",
	"closet",
	"It might be enterable by someone skilled enough",
	"xbox",
	"An original Xbox console. Other than being dusty, it just might still work.\n"+
	"Perhaps you could 'press' the power 'button' and check out what game the\n"+
	"previous owner had last played",
	"tv"
	"An old Zenith television set. It seems it is still on, after all this time.\n"+
	"There is an original Xbox console connected to it",
	});

dest_dir =
({
	"/players/chip/room/apartment/f3h4.c",     "leave",
	});
}

init()
{
::init();

add_action("enter","enter");
	}

enter(str)
{

	if(!str) { write("Enter what?\n"); return 1; }

	if(str != "closet"){ write("What the hell are you trying to enter?\n"); return 1; }

        if(str == "closet" && (this_player()->query_extra_level() < 10)){ write("You are not experienced enough to manage the opening of a simple door... do you not feel like a newbie?\n"); return 1; }

this_player()->move_player("into the dark closet#players/chip/room/apartment/lndlrdclst.c");

add_action("press","press");
	}

enter(str)
{

	if(!str) { write("Press what?\n"); return 1; }

	if(str != "button"){ write("What the hell are you trying to press?\n"); return 1; }

        if(str == "button" && (this_player()->query_extra_level() < 100)){ write("You are not experienced enough to fire up this Xbox, for some strange reason.\n"); return 1; }

	if(str == "button" && (this_player()->query_extra_level() = 100)){ write("There is a "+HIW+"bright flash of light"+NORM+". When it fades, you are somewhere new!\n"); return 1; }

this_player()->move_player("into the dark closet#players/chip/closed/other/HALO/room1.c");

return 1;
}
