#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";
int a;

reset(int arg){
a = random(3);
if(a == 0) {
  if(!present("drifter")) {
move_object(clone_object("/players/daranath/qualtor/mon/drifter.c"),this_object());
  }
}
if(a == 1) {
move_object(clone_object(ROOT+"newstuff/mon/doomdrifter.c"),this_object());
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "The extended hallway with a large mosaic ends here, turning to\n"+
     "the north and continuing along underneath the Crystalline Tower.\n"+
     "The white marble walls are stained with blood and grime here,\n"+
     "leaving the impression that a large battle was recently\n"+
     "fought in this location.\n";

    items=({
     "mosaic","The mosaic ends in the hallway to the west",
     "blood","Dried blood is caked along the walls",
     "grime","Blood and dirt are caked along the walls from a fight here",
     "hallway","The excellent hallway runs both north and west form here",
    });

    dest_dir=({
      "/players/daranath/qualtor/cryst10.c","north",
      "/players/daranath/qualtor/cryst6.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Other then the blood on the walls, there is nothing of interest.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

