#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

int i;

reset(arg){
  if(!present("thibideaux")){ 
    move_object(clone_object("players/softly/algiers/mobs/thibideaux.c"),this_object());
    { 
      for(i=0;i<13;i++) {
	move_object(clone_object("players/softly/algiers/mobs/kids.c"),this_object());
      } 
    }

    if(arg) return;
    set_light(1);
    short_desc = "Algiers School";
    long_desc ="\n"+
      "  The single school room seems larger inside than it appears\n\
from the outside.  The wooden floors are wavy from the feet of\n\
many children.  Long slabs of benches sit in uneven rows, with\n\
planks for desks in front of them.  Several small dirty windows\n\
punctuate the room.  At the front of the room a large desk and a\n\
blackboard dominate the space.\n";

    items = ({
      "room",
      "Grey wooden walls and floors create a seamless vista",
      "floors",
      "The worn wooden floors have deep indentations from\n\
the feet of many children scuffing along",
      "benches",
      "Thick slabs of wood are mounted on 2x4s to create\n\
a sitting space for students",
      "planks",
      "Thick pieces of wood are mounted at a higher level\n\
than the chairs to make a writing surface",
      "desks",
      "The desks are merely wooden planks mounted in front of benches",
      "windows",
      "Six small windows, dirty and covered with screens,\n\
allow the brightness from outside to penetrate",
      "desk",
      "A mahogony colored desk stands in the front of the room",
      "blackboard",
      "A once-black board is pale from years of ground in chalk dust",
    });

    dest_dir = ({
      "/players/softly/algiers/rooms/schlyrd.c","east",
    });
  }
}
