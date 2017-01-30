#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/ghost_ky.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/ghost_gu.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/ghost_gu.c"),this_object());
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "The marble hallway ends at a secure room with a large iron\n"+
     "door, a holding cell of some sort. The door looks as if it\n"+
     "is in good shape, compared to the rest of the area. The\n"+
     "marble hallway runs south from here\n";

    items=({
     "door","The large iron door has a small window with iron bars across it",
     "marble","The dirty white marble hallway runs south",
     "hall","The dirty white marble hallway runs south",
     "hallway","The dirty white marble hallway runs south",
     "cell","The cell was used to temporarily hold prisoners",
    });

    dest_dir=({
      "/players/daranath/qualtor/cryst12.c","east",
      "/players/daranath/qualtor/cryst10.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_east","east");
    }

    search(){
    write("You find nothing of interest with the ruins of the crystal tower.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_east() {
    if(!present("keyone", this_player())) {
    write("You do not have the proper key to open the prison cell.\n");
    say(tp +" tries to open the prison door, but finds it locked.\n");
    return 1;
    }
    if(present("ghost guard")) {
    write("The ghost of the guardsman stands in your way.\n");
    say(tp +" tries to enter the cell, but is stopped by the ghost.\n");
    return 1;
    }
    write("You unlock the prison cell and step in.\n");
    say(tp +" unlocks the prison cell with the proper key and steps inside.\n");
    return 0;
    }

