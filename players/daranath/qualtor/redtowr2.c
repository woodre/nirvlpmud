#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("drifter")) {
move_object(clone_object("/players/daranath/qualtor/mon/drifter.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "The spiraling stairway ends within a room that is completly empty\n"+
     "save for a doorway leading south. The door itself has been\n"+
     "ripped asunder from its hinges, leaving the doorway to\n"+
     "extend into darkness.\n";

    items=({
     "wall","The red stone walls are the same as elsewhere in the tower",
     "doorway","The doorway heads south from here",
     "darkness","Who knows what horros lurk within the darkness",
     "door","The door is no longer here, having long since been removed",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr1.c","up",
      "/players/daranath/qualtor/redtowr3.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing within the area of interest.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


