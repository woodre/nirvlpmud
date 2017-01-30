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

short_desc = HIG+"A Road to Turtleville"+NORM;
long_desc = "   The sun shines bright upon the path.  Small mushrooms line the\n"+
            "road.  To the northest the mushrooms get progressively larger.  The\n"+
            "western path leads into the town of Turtleville.\n";

items = ({
    "mushrooms","They are small with red and white dots.  They get larger to the northeast",
    "path","A dirt path leading to the Mushroom Grove and Turtleville",
    "road","It is paved with smooth stones",
    "stones","They are dull colors and very smooth",
    "sun","A yellow star glowing in the sky",
});

smells = ({
  "default","It smells like a fresh day",
});

listens = ({
  "default","You hear the normal sounds of a cheery day",
});

dest_dir = ({
     "/players/wocket/turtleville/tepath2.c","west",
     "/players/wocket/mushrooms/mg2.c","northeast",
});
set_light(1);
}
