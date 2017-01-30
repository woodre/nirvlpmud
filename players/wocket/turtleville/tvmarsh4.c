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
"   A dead end lies ahead in the muddy water.  Small flowering plants line\n"+
"the area while bushes and trees give a grey backdrop.  Dust filled rays of\n"+
"light seem to give meaning to it all.\n";

items = ({
  "water","It is very muddy and very thick",
  "plants","They are a sickening grey, covered in mud.  The flowers, however\n,are bright and lush",
  "bushes","They are grey and scruffy",
  "trees","With thick trunks and weeping branches the fill in the background",
  "rays","They sparkle with dust",
  "light","It sparkles with dust as it filters through the trees",
});
smells = ({
  "default","It smells very musky",
  "flower","They give off a gentle odor",
});
listens = ({
   "default","You hear the animals of the marsh",
});

  dest_dir = ({
    PATH+"/tvmarsh1.c","south",
  });
set_light(1);
}
