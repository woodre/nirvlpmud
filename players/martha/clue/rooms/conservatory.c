#include "ansi.h"
inherit "room/room";

reset(arg) {
	if(!present("green",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/green.c"), this_object());
	}
	
	if (arg) return;
	set_light(1);
	short_desc = GRN+"The Conservatory"+NORM;
	items = ({
		"outer","Glass forms the outer walls of this room",
		"walls","The outer walls are glass, the inner wall is solid, or is it?",
		"room","This is the conservatory, there are many plants in here",
		"top","The ceiling is at the top",
		"bottom","The floor is at the bottom",
		"water","Clear liquid that helps to keep plants nourished",
		"curved","The glass curves here making it bubble like",
		"glass","Windows made entirely of glass",
		"bubble","Glass that curves out",
		"rain","Water that falls in droplets",
		"row","Plants all in a line",
		"rows","Lines and lines of plants and flowers",
		"leaf","The leaf from a plant",
		"leaves","Leaves from plants",
		"flower","A beautiful red flower",
		"flowers","Assorted flowers that vary in color",
		"study","You can't seem to see the study from here",
		"music","You can't see music, silly!",
		"passageway","There seems to be a 'panel' you can 'push' here",
		"hill","This is the infamous Hill House",
		"house","This is the infamous Hill House",
		"panel","This 'panel' looks as though you could 'push' it",
		"rooms","The only room you can see is the one you are in"});
		
	long_desc =
"	The outer walls of this dark room are all glass from top to bottom.\n\
Water is running down the curved top of the glass bubble due to the rain\n\
that always seems to loom over this particular room.  Rows of plants run\n\
up and down the floor, making it difficult to walk without stepping on a\n\
leaf or flower.  Somehow music from the Study is coming through the inner\n\
panel of wall.  Rumor has it there are secret passageways hidden in a few\n\
of the rooms of Hill House.  Maybe this is one of those rooms?\n";
	dest_dir = ({"players/martha/clue/rooms/hall","southwest",
				 "players/martha/clue/rooms/ballroom","west",
				 "players/martha/clue/rooms/billiard","south"});
}

init() {
  ::init();
  add_action("push","push");
}

int push(string arg) {
  if(arg && arg == "panel") {
    write("You push the panel and are transported elsewhere!\n");
    move_object(this_player(),"/players/martha/clue/rooms/secretpassage.c");
    return 1;
  }
  write("Push what?\n");
  return 1;
}