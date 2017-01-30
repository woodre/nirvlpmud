#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";


reset(arg){
  if(arg) return;
if(!present("sylic",this_object()))
  move_object(clone_object(PATH+"/NPC/sylic.c"),this_object());

  short_desc = HIG+"The Turtleville Advance Hall"+NORM;
  long_desc = ""+
              "   Light shines brightly through the door.  Torches line the\n"+
              "walls as they illuminate the shields and swords that are displayed.\n"+    
              "A small sparring arena is in the center of the room.  Blood\n"+
              "splatters the outlying arena.  On the back wall some pictures of\n"+
              "great battles hang.\n";
  items = ({
    "torches","Metal bowl that hold a bright burning flame",
    "walls","Swords, shields, and pictures are all hung upon the blood\nsplattered walls",
    "pictures","They are of great battles won.  Many are gruesome",
    "shields","They are beaten and battered from much use",
    "swords","Many nicks scar the blade and blood is still dried on",
    "arena","A dirt circle in the middle of the room.  It is well used",
    "blood","It is a deep black as it has dried upon much of the room",
    "door","A wooden door with many decorative holes allowing light through",
  });
  set_light(1);
  dest_dir = ({
    PATH+"/tnpath1.c","west",
  });
}


