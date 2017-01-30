#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
   int x;
      if(arg) return;
   set_light(1);
   if( !present("child") ){
      x = random(3)+2;
      while(x){
            move_object(clone_object(MON+"child.c"),this_object());
            --x;
      }
   }
   short_desc = "The Gameroom";
   long_desc =
"   There are flashing lights whistles and bells going off all over\n\
the place.  The black and white square tiles where the children run\n\
only serve to highten the sense of meyham.  There are several alcoves\n\
around with different games in them.  Off to the west stands a large\n\
hill made of carpet.  To the south is the snackbar.\n";

   items = ({
      "lights","Strobes of all different colors flash from above",
      "tiles","The tiles are a checkered pattern and look a bit used but not worn",

   });

   dest_dir = ({
	AREA+"snackbar2.c","south",
        AREA+"hill.c","west",
        AREA+"crane.c","crane",
        AREA+"gallery.c","gallery",
   });
}

init(){
     ::init();
     add_action("listening","listen");
}

listening(){
     write("Shrill whistles and clamouring bells make hearing much else a chore.\n");
     return 1;
}

realm(){ return "NT"; }
