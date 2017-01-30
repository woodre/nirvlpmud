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
"  Gloomy vines hang from weeping trees stretching to the muddy ground.\n"+
"Small plants and bushes litter the area making many hiding places for\n"+
"small animals.  A fork in the path has been created leading in many\n"+ 
"directions.\n";

items = ({
  "vines","They hang from the many trees looking green and healthy\nwith sharp thorns",
  "trees","They white trunks are covered in mud while their branches hang down",
  "ground","It is covered with muddy water",
  "plants","They litter the area with there colored flowers",
  "bushes","They look scruffy and grey",
  "fork","The path splits going east, west, and north",
  "path","It is a very makeshift path only defined by where one can walk safely",
});

smells = ({
  "default","It smells very musky",
});
listens = ({
  "default","You can hear the animals crawl around the in muddy water",
});

  dest_dir = ({
    PATH+"/tvmarsh7.c","east",
    PATH+"/tvmarsh5.c","west", 
    PATH+"/tvmarsh8.c","north",
  });
set_light(1);
}
