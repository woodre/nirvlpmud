      /*                                                                    
       *    File: /players/chip/room/apartment/f1stairs.c                
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

short_desc = ""+HIR+"A first floor stairwell"+NORM+"";

long_desc =
	"This is the stairwell of the first floor of the abandoned building.\n"+
	"The stairs lead upward, and look extremely dangerous to walk on.\n"+
	"It looks like there used to be a banister along the sides, but it\n"+
	"seems to have been long removed. There is a poorly boarded doorway\n"+
	"here that looks as if someone has busted through it.\n";
	
add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
add_smell("urine", "The scent is strong and makes it difficult to breathe properly");

items =
({
	"stairwell",
	"Very creaky and warped, it still holds just enough to tread upon somehow",
	"banister",
	"It seems to have been removed or rotted away long, long ago",
	"sign",
	"Unlit and now meaningless, it marks the place where the exit door used to be accessible",
	"door",
	"It was nailed shut with oak boards and heavy roofing nails, but is now open other than the boards slightly blocking it",
	"boards",
	"They are poorly nailed to the doorway to block entry. The can be 'shifted' to allow entry",
	"nails",
	"They have been used to secure the oak boards across the doorway to block it",
	"stairs",
	"They lead up to the second floor",
	});

dest_dir =
({
	"/players/chip/room/apartment/f1h3.c",     "west",
	"/players/chip/room/apartment/f2stairs.c",     "ascend",
	});
}

init()
{
::init();

add_action("shift","shift");
	}

shift(str)
{

	if(!str) { write("Shift what?\n"); return 1; }

	if(str != "boards"){ write("What the hell are you trying to move?\n"); return 1; }

        if(str == "boards" && (this_player()->query_extra_level() < 21)){ write("You are not experienced enough to shift the boards out of the way.\n"); return 1; }
	write("You shift the boards and enter the doorway...and are suddenly falling down an empty elevator shaft!\n");
	this_player()->hit_player(50 + random(30));
	this_player()->move_player("into the dark doorway. There is a scream as they fall down an empty shaft!#players/chip/closed/other/SATAN/room1.c");

return 1;
}
