#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  The rays of light from the ceiling seem to group here.  Water flows\n"+
"from all directions into a grate on the ground.  Looking into the holes\n"+
"on the grate only darkness can be seen.  The light makes it difficult to\n"+
"see anywhere but here.\n");

if(!present("lizard"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/lizard2.c"),
	    this_object());

items = ({
  "rays",
  "The light makes it hard to see around the cavern", 
  "ceiling",
  "You are almost blinded by the rays of light from the ceiling", 
  "ground",
  "The water flows into an iron gate on the floor",
  "floor",
  "An iron gate lies in the center of the room",
  "grate",
  "The grate seems to have bars on its sides",
  "bars",
  "Perhaps you could '"+HIR+"pry bars"+NORM+"' to open it."
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_16.c","west",
  "/players/catacomb/Cavern/rooms/lvl3_18.c","east",
  "/players/catacomb/Cavern/rooms/lvl3_17.c","south",
  "/players/catacomb/Cavern/rooms/lvl3_19.c","north" 
});
}

init()
{
  ::init();
      add_action("grate","pry");  
}

grate(str)
{
  if (str == "bars")
  {
    write("You pry the bars and the grate opens up allowing passage through.\n");
    TP->move_player("pry#players/catacomb/Cavern/rooms/lvl4_1.c");
    return 1;
  }
  else 
  {
    write("Pry what?\n");
    return 1;
  }
}
