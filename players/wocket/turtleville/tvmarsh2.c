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
"   The marsh takes over from the once well kept path.  Back south is the\n"+
"village.  The trees loom everywhere and water saturates the muddy ground\n"+
"There are more passages through the bushes to the east, north, and west.\n";

items = ({
  "path","It is a well keep path to the south",
  "trees","They weep with vines covering them",
  "water","It forms puddles and mud",
  "ground","It is very muddy and still has the tracks of past prey",
  "passages","They lead through the marsh",
  "bushes","They are very scruffy and prickly",
});

smells = ({
  "default","It smells very musky",
});
listens = ({
  "default","You hear the animals of the marsh",
});
  dest_dir = ({
    PATH+"/tvmarsh1.c","west",
    PATH+"/tvmarsh3.c","east",
    PATH+"/tvmarsh5.c","north",
    PATH+"/tnpath4.c","south", 
 });
set_light(1);
}
