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

short_desc = ""+YEL+"desert"+NORM+" "+HIK+"road"+NORM+"";

long_desc =
	"On and on, goes this long desert road.....but suddenly, a dead end.\n"+
	"The road goes as far as the eye can see in one direction...and in \n"+
	"the other, there are many large craters in the land, from nuclear\n"+
	"weapons testing. You feel as though you are being watched, and\n"+
	"may find it in your best interest to leave....soon.\n";

add_smell("air", "The smell of your own fear overcomes you.");    
add_listen("sounds", "You hear....nothing, making things that much more ominous.");
items =
({
	"road",
	"A very long, dusty desert road. In this case, it just might be\n"+
	"the highway to Hell, if you will",
	"craters",
	"They look to be about a football field in diameter, and many are\n"+
	"filled with old junked cars for some strange reason..",
	"cars",
	"A half dozen or more in each crater, these vehicles, though still\n"+
	"tagged, look to be long abandoned. What has happened here?",
	});

dest_dir =
({
	"/players/chip/room/movies/room6.c",     "north",
	"/players/chip/room/movies/room5.c",     "northwest",
	"/players/chip/room/movies/room7.c",     "northeast",
	"/players/chip/room/movies/room9.c",     "south",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("You might not want to search too hard, my friend...\n");
return 1;
}
if(str == "crater" && dead){
write("There is nothing to find here, other than what can be immediately seen.\n");
return 1;
}
if(str == "crater" && !dead){
write("Two deformed humanoids come out of nowhere in a violent rage!\n");
move_object(clone_object("/players/chip/mobs/movies/mutant2.c"), this_object());
move_object(clone_object("/players/chip/mobs/movies/mutant1.c"), this_object());
dead = 1;
return 1;

}
}
