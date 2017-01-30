inherit "/room/room";
#include "/players/autumn/defs.h"

reset(arg) {

    if(arg) return;
    set_light(1);

short_desc=(BOLD+YEL+"ESC Cinemas: "+NORM+HIG+"Hallway"+NORM);

long_desc=
 
HIK+"A hallway:\n"+NORM+YEL+
"This is the hallway leading to the theaters.  The hallway is wide, with a beige and brown\n"+
"patterned carpet, circular lights hanging from the ceiling, and hunter green walls. \n"+
"There is a water fountain next to the wall.  A sign hangs over a theater doorway.  The \n"+
"hallway is very busy with many patrons coming in and out of their theaters.  There are \n"+
"several ushers nearby working.  Theaters 1-4 are to the west east.  Theater 5 is right \n"+
"across the hall.\n"+NORM+HIK;  



items = ({
  
  "theater","The entrance to a theater",
  "door","The entrance to a theater",
  "carpet","A unique pattered carpet. It's rather new",
  "lights","Beautiful light fixtures",
  "ceiling","There is nothing special about the ceiling",
  "walls","Hunter green walls",
  "fountain","A refreshing water fountain",
  "sign","Theater #5: The Cube",


});

dest_dir = ({
  "/players/autumn/cinemas/rooms/theater5.c","theater",
  "/players/autumn/cinemas/rooms/hall4.c","west",

  
  
});

}

init()
{
  ::init();
  add_action("search","search");
  add_action("smell","smell");
  add_action("listen","listen");
}

search()
{
  write("You're in a hallway, stupid. What could you possibly find?\n"); 
  say(TPN+" looks around.\n");
  return 1;
}

smell()
{
	write("Yummy smells of buttered popcorn and candy are everywhere.\n");
	return 1;
}

listen()
{
	write("You hear popcorn popping!\n");
	return 1;
}

