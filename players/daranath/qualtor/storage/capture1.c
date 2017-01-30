#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/hogre1.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"(*unknown*)");
    long_desc=
     "Boxes and crates fill the main area of the building, giving it\n"+
     "a strong warehouse feel. A smaller room stands against the\n"+
     "southern wall, its doorway covered by a dark red curtain. The\n"+
     "only other exit is back out the way you came.\n";

    items=({
     "boxes","The boxes are stacked along the far walls",
     "crates","The crates are stacked with the boxes",
     "curtain","A dark red curtain hangs across the doorway leading south.\n"+
               "hiding what the room contains from your sight",
    });

    dest_dir=({
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_south","south");
add_action("dar_back","back");
    }

    search(){
    write("You find nothing of interest within the area.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_south() {
      if(present("ogre")) {
      write("The Huge Ogre stands in your way from moving further into the building.\n");
      write("The Huge Ogre says: Begone!!!  You are not welcome here.\n");
    return 1; }
      write("You move aside the curtain and step into the small room.\n");
    return 0; }
