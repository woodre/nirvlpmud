inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("sneezer", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/sneezer.c"), this_object());
if(!present("fowl", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/fowl.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = "A Small "+HIK+"Road "+NORM+"in "+HIC+"Tiny"+HIW+" Toon"+HIC+" Town"+NORM+"";
  long_desc = " A small simple road leading into tiny toon town. To the east is a creepy\n\
  little house towards the end of town. To the north a desert canyon can\n\
  be seen. Back to the south goes back into town on the small narrow road.\n";
  items = 
  ({
    "canyon",
    "A Huge dry desert canyon",
    "house",
    "A little creepy house that has the echo of scared animals coming from it",
    "canyon",
    "A small desert canyon far off in the distance",
    "desert",
    "A small desert canyon far off in the distance",
  });
    dest_dir=({
  "/players/wicket/tv/looney/rooms/toonroad3","south",
  "/players/wicket/tv/looney/rooms/elmyrahouse.c","east",
  "/players/wicket/tv/looney/rooms/canyon.c","north",
  });
  } 