#include "/players/wocket/closed/ansi.h"
#define PED "/players/wocket/turtleville/NPC/ped.c"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
if(random(2)==1){
if(!present("ped",this_object()))
  move_object(clone_object(PED),this_object());
 if(random(2)==1){
  move_object(clone_object(PED),this_object());
 }
}
  if(arg) return;

short_desc = HIG+"Turtleville"+NORM;
long_desc = "   Houses line this narrow road of Turtleville.  Clouds litter\n"+
            "the cyan sky, filtering the light from the sun.  The road leads\n"+
            "to the west, taking its travelers into town, or east, out to the\n"+
            "Mushroom Grove.\n";

items = ({
    "clouds","They are puffy and white",
    "sky","It is a brillant cyan color",
    "houses","The houses of the people of Turtleville look quaint with turtle \nshell like roofs",
    "sun","It's light is being filtered by the clouds",
    "road","It is paved with smooth stones",
    "stones","They are many different dull colors and very smooth",
});

smells = ({
  "default","It smells like a fresh day",
});

listens = ({
  "default","You hear the normal sounds of a cheery day",
});

dest_dir = ({
    "/players/wocket/turtleville/tville_fount.c","west",
    "/players/wocket/turtleville/tepath2.c","east",
});
set_light(1);
}
