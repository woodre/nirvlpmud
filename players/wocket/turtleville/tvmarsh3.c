#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
if(random(2) == 1){
  move_object(clone_object(PATH+"/NPC/turtle.c"),this_object());
}
if(random(2) == 1){
    move_object(clone_object(PATH+"/NPC/turtle.c"),this_object());
}
if(random(2) == 1){
      move_object(clone_object(PATH+"/NPC/turtle.c"),this_object());
}

  if(arg) return;

short_desc = HIG+"Turtleville Marsh"+NORM;
long_desc = ""+
"   Muddy water surround everything.  Trees weep in the gloom and along\n"+
"with many bushes form a dead end in this marsh.  Sounds of animals moving\n"+
"through the marsh shatters any silence.  Dim light filters through the \n"+
"canopy.\n";

items = ({
  "water","It is very muddy and thick",
  "trees","Thick healy trucks with their long branches hanging down to\nthe ground",
  "bushes","They are very dirty with sharp leaves",
  "canopy","It is formed by all the weeping trees",
  "light","It filters through the canopy",
  "marsh","Many trees and bushes grow from the muddy water",
});

smells = ({
  "default","It smells very musky",
  "sounds","The rustling of leaves and the breaking of branches",
});

listens = ({
  "default","You hear the sounds of the animals of the marsh",
  "animals","You hear them crawling through the wet marsh",
});
  
 dest_dir = ({
    PATH+"/tvmarsh2.c","west",
  });
set_light(1);
}
