#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("marie")){ 
    move_object(clone_object("players/softly/algiers/mobs/marie.c"),this_object());
  }

  if(arg) return;
  set_light(1);
  add_smell("room","The scent of flowers is thick in the room.");
  short_desc = "Red house";
  long_desc ="\n"+
    "  The dim front room has flowered wallpaper and gold brocade\n\
furniture.  Beyond the sofa and chairs is a round wooden table\n\
covered in a white lace cloth.  Four wooden chairs are pushed\n\
under the table.  A round glass globe sits in the center. The\n\
scent of flowers hangs heavy in the room.\n";

  items = ({
    "orb",
    "A clear crystal sphere rests on the table",
    "room",
    "A cozy living room with a dining area attache",
    "wallpaper",
    "Pale blue wallpaper with thin white stripes and large\n\
dark rose colored flowers",
    "furniture",
    "A sofa and two arm chairs are covered with gold brocade\n\
fabric.  They look very comfortable",
    "sofa",
    "The gold brocade covered sofa will seat three",
    "chairs",
    "Two armchairs covered in gold brocade sit beside the sofa.\n\
Four wooden straight backed chairs are pushed under the table",
    "table",
    "A round wooden table is covered with a white lace table\n\
cloth.  A large crystal orb sits in the center",
    "globe",
    "A clear crystal sphere rests on the table",
"scent",
    "The room smells strongly of flowers",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/yard.c","west",
  });
}
