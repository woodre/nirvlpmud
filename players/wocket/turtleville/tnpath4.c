#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;

short_desc = HIG+"Turtleville"+NORM;
long_desc = ""+
"   The paved road ends here and to the north a dirt one leads into the \n"+
"marsh.  The drooping trees lend themselves to the wavering shadows in the\n"+
"background.  East leads back into Turtleville.  You can still hear\n"+
"the chatter from the city.\n";

items = ({
  "stones","They are very smooth and have been walked on by many feet",
  "road","It is paved with very smooth stones",
  "trees","The branches are weeping over the road.  They look healthy but sad",
  "shadows","They waver as the wind blows the trees which cast them",
});
  
smells = ({
   "default","It smells fresh and bright",
});

listens = ({
    "default","You hear the people talking about daily affairs in the background",
    "chatter","You hear the people talking about daily affairs in the background",
});
  
  dest_dir = ({
    PATH+"/tnpath3.c","east",
    PATH+"/tvmarsh2.c","north",
  });
set_light(1);
}
