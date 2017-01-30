#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;

short_desc = HIG+"Turtleville"+NORM;
long_desc = "   More stones line this road as one heads to the west into Turtleville.\n"+
            "Back to the east exists the Mushroom Grove, while to the southeast a narrow\n"+
            "mysterious dirt path winds out of sight.\n";
items = ({
    "clouds","They are puffy and white",
    "sky","It is a brillant cyan color",
    "sun","A giant yellow star in the sky",
    "road","It is paved with smooth stones",
    "stones","They pave the road and are very smooth from the wear of travelers",
    "turtleville","You can see the roofs of many houses and shops",
    "grove","You can see many giant mushrooms in the distance",
    "path","A unkept dirt path that winds southeast and out of sight",
});

smells = ({
  "default","It smells like a fresh day",
});

listens = ({
  "default","You hear the normal sounds of a cheery day",
});

dest_dir = ({
    "/players/wocket/turtleville/tepath1.c","west",
    "/players/wocket/turtleville/tepath3.c","east",
    "/players/wocket/turtleville/tepath4.c","southeast",
});
set_light(1);
}
