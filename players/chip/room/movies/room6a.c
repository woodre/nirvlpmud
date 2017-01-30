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

short_desc = ""+HIB+"An island somewhere on the Amazon River"+NORM+"";

long_desc =
	"This very small piece of ground that protrudes from the center\n"+
	"of the river is heavily vegetated. It is difficult to see anything\n"+
	"around you, other than the abundant plantlife and various small bugs\n"+
	"and animals. The air is extremely calm and fresh-smelling. Something\n"+
	"causes the leaves on a nearby tree to rustle, then all is calm again.\n";
	
add_smell("air", "It smells fresh and soothing.");
add_listen("sounds", "Birds are chirping, monkeys gibbering, bugs buzzing....the usual.");
add_listen("wildlife", "Birds are chirping, monkeys gibbering, bugs buzzing....the usual.");
items =
({
	"island",
	"A small, isolated island out in the middle of the water",
	"ground",
	"A mixture of dirt and sand it seems, with a few leaves laying around,\n"+
	"strangely still green. There is a small hole here",
	"plantlife",
	"Plants of many different types litter the area",
	"plants",
	"Plants of many different types litter the area",
	"bugs",
	"There are quite a few large mosquitos and flies about, but not\n"+
	"much else in the way of insects",
	"animals",
	"There are a few small and medium sized snakes, and a few strange\n"+
	"looking lizards. In the trees you can hear birds that you cannot\n"+
	"see from where you stand",
	"hole",
	"There are many bones here, but no obvious explanation as to why",
	});

dest_dir =
({
	"/players/chip/room/movies/room6.c",     "swim",
	});
		
}
void init(){::init();add_action("cmd_search", "search");}
status cmd_search(string str){
if(!str){
write("You feel a bit uneasy just reaching around aimlessly.\n");
return 1;
}
if(str == "tree" && dead){
write("You search the tree, only to find the remains of a huge snake.\n");
return 1;
}
if(str == "tree" && !dead){
write("A HUGE anaconda slides down from the tree and lunges at you!\n");
move_object(clone_object("/players/chip/mobs/movies/anaconda.c"), this_object());
dead = 1;
return 1;
}
}
