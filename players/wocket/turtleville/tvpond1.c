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
if(random(2) == 1){
  move_object(clone_object(PATH+"/NPC/turtle.c"),this_object());
}
if(random(2) == 1){
    move_object(clone_object(PATH+"/NPC/duck.c"),this_object());
}
if(random(2) == 1){
      move_object(clone_object(PATH+"/NPC/duck.c"),this_object());   
}
  if(arg) return;

short_desc = HIG+"Turtleville Pond"+NORM;
long_desc = ""+
"   A small little pond.  Trees are scattered around the area giving cool\n"+
"shade from the sun.  The sky is bright with clouds spacing out the blue\n"+ 
"background.  Grass carpets the area making soft places for picnics.  Flowers\n"+
"grow all around giving a small bit of color.\n";
items = ({
  "trees","They are very tall and give shade from the sun",
  "grass","It is very soft and a healthy looking green",
  "clouds","They are puffy and white",
  "sky","A brilliant blue.  It has many clouds scattered throughout it",
  "flowers","They are wild flowers of many colors and sizes.",  
  "pond","The pond is a nice blue with small ducks swimming in it",
});

smells = ({
  "default", "It smells like a fresh day",
  "flowers","They give off a pleasant aorma",
});

listens = ({
   "default","You hear the animals of the pond",
});

  dest_dir = ({
    PATH+"/tspath1.c","northwest",
  });
set_light(1);
}
