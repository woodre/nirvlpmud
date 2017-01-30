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

short_desc = ""+HIB+"Somewhere on the Amazon River"+NORM+"";

long_desc =
	"With lush trees and other plant life all around, the air is fresh\n"+
	"and you feel strangely at ease. The water is cool, still, and a bit\n"+
	"muddy. Further out in the water is a small, heavily vegetated island\n"+
	"that you could swim to. There are sounds of wildlife all around you,\n"+
	"and everything makes for a relaxing setting.\n";

add_smell("air", "It smells fresh and soothing.");
add_listen("sounds", "Birds are chirping, monkeys gibbering, bugs buzzing....the usual.");
add_listen("wildlife", "Birds are chirping, monkeys gibbering, bugs buzzing....the usual.");
items =
({
	"trees",
	"Several different kinds of trees cover the area. They are very lush\n"+
	"and green, and most are fairly tall",
	"plants",
	"Plants of many different types litter the area",
	"water",
	"It looks like it's fairly clean and fresh, other than being\n"+
	"a little muddy. It's unusually calm",
	"island",
	"A small, isolated island out in the middle of the water. You could\n"+
	"swim out to it and take a closer look around if you wanted to",
	});

dest_dir =
({
	"/players/chip/room/movies/room6a.c",     "swim",
	"/players/chip/room/movies/room4.c",     "north",
	"/players/chip/room/movies/room5.c",     "west",
	"/players/chip/room/movies/room7.c",     "east",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("Are you stupid?\n");
return 1;
}
if(str == "water" && dead){
write("There is nothing to find here, other than what can be immediately seen.\n");
return 1;
}
if(str == "water" && !dead){
write("You feel a sharp bite into your flesh...and then another...you're being eaten!\n");
move_object(clone_object("/players/chip/mobs/movies/pirahna.c"), this_object());
dead = 1;
return 1;
}
}
