/*
*      Function:
*      Change History:
*/
#include <ansi.h>
inherit "/room/room";

int dead;

reset(arg)
{
::reset(arg);

if(arg) return;

set_light(1);

dead = 0;

short_desc = ""+RED+"An ominous stretch of highway"+NORM+"";

long_desc =
	"You're walking along a long highway in the middle of nowhere... there\n"+
	"hasn't been anyone for miles, and not likely to be for many more. You\n"+
	"then suddenly realize that there's a broken down car on the side of the\n"+
	"road, and decide to stop and take a peek around.\n";

add_smell("air", "There's not alot to smell here honestly.");    
add_listen("sounds", "There is nothing to hear.");
items =
({
	"highway",
	"You have seen nothing for many miles, except the abandoned car sitting here",
	"car",
	"It's an old black Grand Am, but from here there seems to be no one around it,\n"+
	"or inside it",
	});

dest_dir =
({
	"/players/chip/room/movies/room10.c",     "west",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("Only thing around to search is the car.\n");
return 1;
}
if(str == "car" && dead){
write("Just a few audio tapes are in the car, not even anything worth listening to.\n");
return 1;
}
if(str == "car" && !dead){
write("A semi-rough looking man leaps out from behind the car and fires a pistol at you!\n");
move_object(clone_object("/players/chip/mobs/movies/hitcher.c"), this_object());
dead = 1;
return 1;

}
}
