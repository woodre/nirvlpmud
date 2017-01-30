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
"   Vines hang down from swampy trees.  Water floods through the ground \n"+
"making puddles everywhere.  The surroundings appear gloomy even though rays\n"+
"of dust filled light shine through.\n";

items = ({
  "vines","They are long and hang down from trees",
  "trees","Many weeping trees give shade and darkness",
  "water","Large puddles of muddy, thick water",
  "puddles","They very dirty and everywhere",
  "rays","Dusty rays of light shine through the trees",
  "light","It is filtered and sparkles with dust",
});

smells = ({
  "default", "It smells very musty",
});

listens = ({
   "default","You hear the animals of the marsh",
});

  dest_dir = ({
    PATH+"/tvmarsh2.c","east",
    PATH+"/tvmarsh4.c","north",
  });
set_light(1);
}
