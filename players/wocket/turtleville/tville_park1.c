#include "/players/wocket/closed/ansi.h"
#define PED "/players/wocket/turtleville/NPC/ped.c"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
if(!present("statue",this_object()) )
  move_object(clone_object("/players/wocket/turtleville/OBJ/statue.c"),this_object());
 if(random(2)==1){
  move_object(clone_object(PED),this_object());
 }
  if(arg) return;
 
short_desc = HIG+"Turtleville"+NORM;
long_desc = "   A metal gate marks the entrance of the park.  Through the gate to\n"+
            "the south is the road.  West leads deeper into the park.  Birds sing\n"+
            "their songs from high uptop the tree.  The trees cast a wonderful shade\n"+
            "down upon the ground giving the breeze a slight chill.\n";
items = ({
    "gate","It is made of black metal and designed with many swooping curves.\nIt swings back and forth in the breeze.",
    "clouds","They are puffy and white",
    "sky","It is a brillant cyan color",
    "trees","They are healthly looking with green leaves and cast shade upon the park",
    "flowers","Many different colored flowers",
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
   "/players/wocket/turtleville/tville_park2.c","west",
   "/players/wocket/turtleville/twpath2.c","south",
});
set_light(1);
}
