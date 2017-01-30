#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("boddy",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/boddy.c"), this_object());
}*/

	if (arg) return;
	set_light(1);
	short_desc = HIR+"The Study"+NORM;
	items = ({
		"study","This room is dimly lit and furniture is scarce",
		"table","A small end table that is big enough to hold a lamp and a drink or a phonograph",
		"lamp","A clay lamp with a flowery shade holds a low wattage bulb",
		"shade","A shade with flower shapes cut out of it",
		"small","This is a small end table",
		"end","This is a small end table",
		"brown","Brown is the color of the leather couch",
		"leather","The couch is made of brown leather",
		"couch","The couch is brown leather and looks polished",
		"chair","A brown leather armchair",
		"bookshelf","The bookself is lined with books",
		"wall","The wall is lined with books or pictures, depending on which you are viewing",
		"walls","The walls are line with books and pictures",
		"books","Various books line the shelf",
		"book","A large hard covered book",
		"picture","A picture of a little girl and her dog",
		"pictures","Various pictures of children and animals hang here",
		"fireplace","The fireplace is made of bricks. One of the 'brick's looks like it is 'move'able",
		"room","This is the study",
		"phonograph","An old fashioned recording device",
		"rooms","You can only see the study from here",
		"passageway","There seems to be a 'brick' you can 'move' here",
		"hill","This is the infamous Hill House",
		"house","This is the infamous Hill House"});
		
	long_desc =
"	The study is dimly lit as there is only one table lamp in the entire\n\
room.  The clay lamp with cut out flowers on its shade sits on a small\n\
end table next to the brown leather couch.  Aside from the couch, there\n\
is only one other chair in the room.  There is a bookshelf along one of\n\
the walls and pictures hanging on the other.  There is a phonograph on\n\
an end table next to the chair.  There is a fireplace that is built into\n\
the inner wall.  Rumor has it there are secret passageways hidden in\n\
various rooms of Hill House, perhaps there is one hidden here.\n";
	dest_dir = ({"players/martha/clue/rooms/droom","east",
				 "players/martha/clue/rooms/hall","northeast",
				 "players/martha/clue/rooms/library","north"});
}

init() {
  ::init();
  add_action("move","move");
}

int move(string arg) {
  if(arg && arg == "brick") {
    write("You move the brick and are transported elsewhere!\n");
    move_object(this_player(),"/players/martha/clue/rooms/secretpassage.c");
    return 1;
  }
  write("Move what?\n");
  return 1;
}
  