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
"   Weeds stick out from the marsh waters as grass grows tall and thick.\n"+
"The trees have thinned a bit and give way to lakes of water and grass, \n"+
"which seem impossible to cross.  Far in the distance the other shore\n"+
"is faintly visible.  \n";

items = ({
  "weeds","Their tall shafts stick out from the waters and are covered\nwith spiky barbs",
  "grass","It is very long and unkept",
  "trees","They are old and weathered with weeping branches",
  "waters","It is very muddy and wet",
  "distance","You can see another shore",
  "shore","It is off in the distance with trees and bushes.  It looks very\nsimilar to this one",
});
smells = ({
  "default","It smells fresh and airy",
});
listens = ({
  "default","You can hear the animals of the marsh",
});

  dest_dir = ({
    PATH+"/tvmarsh6.c","south",
  
  });
set_light(1);
}
