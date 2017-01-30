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
"   A path continues to the east and south.  Many trees give dark shade to\n"+
"the area.  Vines hang down creating curtains in the marsh as muddy water\n"+
"covers the ground.\n";

items = ({
  "path","It leads to the east and south",
  "trees","Thick trunks covered with mud and long branches that bend to\nthe ground",
  "vines","They are long and covered with leaves",
  "curtains","They are made from the hanging vines",
  "water","It is very muddy and thick",
  "ground","It is flooded with water making mud everywhere",
});
smells = ({
  "default","It smells very musky",
});
listens = ({
  "default","You hear the sounds of the marsh",
});

  dest_dir = ({
    PATH+"/tvmarsh6.c","east",
    PATH+"/tvmarsh2.c","south", 
  });
set_light(1);
}
