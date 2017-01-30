#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
if(!present("banus",this_object()))
  move_object(clone_object("/players/wocket/turtleville/NPC/shoppekeeper.c"),this_object());

  if(arg) return;

  short_desc = HIG+"The Turtleville Shoppe"+NORM;
  long_desc = "   "+
              "A small little shop.  The dusty wooden floor squeaks underneath\n"+
              "the slightest pressure.  Boxes of merchandise line the walls\n"+
              "and the shelves hold many nicknacks of turtillian items.  A small\n"+
              "counter with a register block the entrance to the back room.\n";
  set_light(1);
items = ({
   "floor","The wooden floor has been worn down over the years.  Dust and\n"+
           "dirt littering every corner",
   "boxes","Brown cardboard boxes are stacked to the ceiling", 
   "merchandise","They are in the boxes",
   "walls","They can hardly be seen behind all the boxes",
   "shelves","Rows of shelves fill the store holding many nicknack items",
   "nicknacks","Small necessities made from the remains of dead turtles",
   "items","Small necessities made from the remains of dead turtles",
   "counter","An old wooden counter supporing the register",
   "register","A very old register with large keys",
   "entrance","Through the open door you see move shelves of merchandise",
});
listens = ({
    "default","You hear the squeak of the floor",
    "floor","It squeaks as any pressure is applyed to it",
});
smells = ({
    "default","You smell dust and age",
});

   dest_dir = ({
    PATH+"/tnpath1.c","east",
  });
}

