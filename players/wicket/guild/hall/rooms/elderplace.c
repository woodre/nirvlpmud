inherit "/room/room";
#include <ansi.h>
#include "../../defs.h"


reset(arg) {
	if (!present("board")) {
		move_object(clone_object("/players/wicket/guild/hall/objs/board.c"), this_object());
	}
::reset(arg);
  set_light(1);
  short_desc = "Elder Council of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM;
  long_desc = 
	  "An ancient meet pleace where the elders of this guild conduct business\n"+
	  "and organize guild issues and see over all the Elementalists within the guild.\n"+
	  "This room is for the Elders of the guild only. The walls swirl around the with\n"+
	  "immense energy as they pulsate. Runes of the four Elements are carved into the\n"+
	  "floor. A large round table sits in the center of the room with chairs around \n"+
	  "it. An orb glows and floats at the center of the table.\n";
  items = 
  ({
    "table",
    "A very old wooden table that has had business conducted around it for ages",
    "orb",
    "An ancient orb that is placed in the center of the table as the symbol of our guild",
    "walls",
    "All kinds energy flows from the walls as the swirl and change colors of the four elements",
    "runes",
    "Runes of the four elements that have been carved into the floor that seem to have a strange glow",
  });
    dest_dir=
({
	HALLRMS+"entrance.c",   "down",
  
  });
  } 
  
realm(){ return "NT"; }
query_no_fight(){ return 1; }