#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";
int a;

reset(int arg){
a = random (3);
if(a < 2) {
if(!present("reaver")) {
move_object(clone_object(ROOT+"mon/reaver.c"),this_object());
  }
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
"The white marble hallway continues north and south from your\n"+
"current location, blood and grime covering the walls all about\n"+
"you. The walls are heavily scarred from weapon hits and\n"+
"ragged claw marks tearing into the pure marble.\n"+
"The hallway has collapsed, preventing any further travel northwards.\n";

    items=({
     "marble","The white marble is covered in blood and grime",
     "marks","Large claws have torn away huge chunks of the marble",
     "claw marks","The claws marks were made by something BIG",
     "mark","Each claw mark is different from the others",
     "blood","The dried blood is dark red against the pure white marble",
     "grime","nasty",
    });

    dest_dir=({
 "/players/daranath/qualtor/cryst9.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing of interest with the ruins of the crystal tower.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

