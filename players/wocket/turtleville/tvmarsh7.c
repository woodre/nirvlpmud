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
"   A small lake bars passage further east.  Trees give shade with their long\n"+
"branches as bushes fill in between them.  Puddles of water cover footprints\n"+
"in the mud stricken ground.\n";

items = ({
  "lake","A small lake filled with mud and weeds",
  "trees","They have very long branches that hang down from tall thick trunks",
  "bushes","They look very menacing with their grey hard leaves and sharp branches",
  "footprints","Many animal tracks are left in the muddy ground, filled with water",
  "ground","It is covered with mud and puddles of water",
  "puddles","They are very dirty and thick with mud",
  "water","It is very dirty and thick with mud",
  "mud","Its brown and squishy",
  "hut","A small hut hidden in the thick grass.\nYou may want to 'enter' it",

});
smells = ({
  "default","It smells very musky",
});
listens = ({
  "default","You can hear the small chirps of birds",
  "birds","They chirp in the distance",
});

  dest_dir = ({
    PATH+"/tvmarsh6.c","west",
  
  });
set_light(1);
}

init(){
  ::init();
 add_action("search","search");
 add_action("enter","enter");
}

search(){
  write("You search through the tall grass and find a hut hidden\n"+
        "deep with in them.  You might want to 'enter' it.\n");
  return 1;
}

enter(str){
 if(str != "hut"){
   notify_fail("What would you like to enter?\n");
   return 0;
 }
this_player()->move_player("into the hut#/players/wocket/turtleville/questhut.c");
return 1;
}
