/*
*      Function:
*      Change History:NEED MADE INTO HEALS SHOP
*      SOUTH EXIT HIDDEN - OPENS WITH HIDDEN PRY BAR UNDER COUNTER IN ROOM7.C
*/
#include <ansi.h>
inherit "/room/room";

reset(arg)
{
::reset(arg);

if(arg) return;

  set_no_clean(1);
set_light(3);

short_desc = ""+HIK+"("+NORM+""+HIC+"Nirvana Cinemas"+NORM+""+HIK+")"+NORM+" "+HIK+"Snack Stand"+NORM+"";

long_desc =
	"As you stand here you cannot believe this room is free of bloodshed.\n"+
	"There is a short man in a black cloak here, seemingly selling some\n"+
	"various snackfoods for horrified on-lookers to munch on while the\n"+
	"horror carries on. It seems to be peaceful here, though screams and\n"+
	"growls of all kinds fill the air in the distance. There is a doorway\n"+
	"to the south, but it is heavily barred and welded shut.\n";
	
add_listen("screams", "They sound like someone is really getting hurt. Oh the fun!");
add_listen("growls", "You get the feeling that you really don't want to know....");

	items =
({
	"man",
	"All you can tell about him is he's got a deep voice, wears a black\n"+
	"canvas cloak, and has some delicious snack items to sell you. Just\n"+
	""+CYN+"ask"+NORM+" him about them for more information",
	"stand",
	"It's a small snack stand, run by a short man in a black cloak.",
	"doorway",
	"The doorway is barred up and welded completely shut",
	"snacks",
	"You have to "+CYN+"ask"+NORM+" the man in the cloak to see them",
	});

dest_dir =
({
	"/players/chip/room/movies/room8.c",     "north",
	});

}
