#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
if(arg) return;

move_object("/players/wocket/turtleville/OBJ/bench.c",this_object());
move_object("/players/wocket/turtleville/OBJ/tree.c",this_object());
short_desc = HIG+"Turtleville"+NORM;
long_desc = "   Trees line this small park.  Flowers are spread around the area giving\n"+
            "color to the green background.  Birds chirp in the trees as wind rustles\n"+
            "leaves.  The sun shines down allowing trees to cast shade.\n";
items = ({
    "clouds","They are puffy and white",
    "sky","It is a brillant cyan color",
    "trees","They are healthly looking with green leaves and cast shade upon the park",
    "flowers","Flowers like tulips, lilacs, and violets grow in garden patches",
    "leaves","They are wide healthy green leaves",
    "shade","Shade cast by the many trees",
    "sun","It's light is being filtered by the clouds",
    
});

smells = ({
  "default","It smells like a fresh day",
  "flowers","They smell wonderful",
});

listens = ({
  "default","You hear the normal sounds of a cheery day",
  "birds","They chirp from the trees",
});

dest_dir = ({
   "/players/wocket/turtleville/tville_park1.c","east",
});
set_light(1);
}
