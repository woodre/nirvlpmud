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

short_desc = "A large, "+HIY+"dusty"+NORM+" yard";

long_desc =
	"This almost desert-like yard is somewhat clouded with dust and dirt.\n"+
	"There is a tree with a chain tied around it and a large doghouse by\n"+
	"the back door of the main house. A water bowl and food bowl both sit\n"+
	"in front of the doghouse to the left of the entrance and the chain\n"+
	"that is hooked to the tree leads into the doghouse. There is a faint\n"+
	"breathing sound.\n";

add_listen("breathing", "You hear a deep, rapid breathing sound coming from inside the doghouse.");
items =
({
	"yard",
	"It's clouded with dust, you can't make much of anything out.\n"+
	"But you definately hear something, almost like a heavy breathing",
	"doghouse",
	"A large doghouse made of wood, with a plank hanging over the\n"+
	"entrance that says "+HIR+"Cujo"+NORM+" on it",
	"plank",
	""+HIR+"Cujo"+NORM+"",
	"house",
	"A large white house, fairly well kept.",
	});

dest_dir =
({
	"/players/chip/room/movies/enter.c",     "leave",
	"/players/chip/room/movies/room2.c",     "northwest",
	"/players/chip/room/movies/room3.c",     "northeast",
	"/players/chip/room/movies/room5.c",     "southwest",
	"/players/chip/room/movies/room6.c",     "south",
	"/players/chip/room/movies/room7.c",     "southeast",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("You don't feel comfortable doing this right now.\n");
return 1;
}
if(str == "doghouse" && dead){
write("Nothing more than a dog chain with nothing hooked to it.\n");
return 1;
}
if(str == "doghouse" && !dead){
write("An angry looking dog, foaming at the mouth, approaches you as you try to enter his home.\n");
move_object(clone_object("/players/chip/mobs/movies/cujo.c"), this_object());
dead = 1;
return 1;
}
}
