#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
#define PED "/players/wocket/turtleville/NPC/ped.c"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
if(random(2)==1){
if(!present("ped",this_object()))
  move_object(clone_object(PED),this_object());
 if(random(2)==1){
  move_object(clone_object(PED),this_object());
 }
}
  if(arg) return;

short_desc = HIG+"Turtleville"+NORM;
long_desc = ""+
"   Houses are sparse as one continues to the west.  The street is paved\n"+
"with soft worn stones that have been walked upon by many feet.  The stone\n"+
"begins to give way to dirt as grass pokes through the holes.  To the east\n"+
"leads back into town.  To the north is a metal gate which is swinging open.\n";


items = ({
  "gate","An open gate to the north.\nIt is made of black metal and sculpted with swooping curves",
  "sun","It is very bright and blinds you as you look upon it",
  "trees","They block the road to the west",
  "houses","There are some houses that line the street",
  "street","It is paved with very soft rounded stones",
  "stones","They are soft to the touch and look worn by much travel",
  "roofs","The are bright green and have the markings of turtles",
  "center","That is to the east",
  "grass","Small patches of bright green grass.  They poke through the street",
  "dirt","More soft, dark dirt is shown around the stones",
});

listens = ({
  "default","You hear the sounds of a bright day",
});
smells = ({
  "default","You smell the fresh air",
});

  dest_dir = ({
    PATH+"NOT_DONE.c","west",
    PATH+"/twpath1.c","east",
    PATH+"/tville_park1.c","north",
  });
set_light(1);
}

init(){
  ::init();
  add_action("new_west","west");
}

new_west(){
write("The road is blocked by some fallen trees.\nYou cannot continue that way.\n");
return 1;
}