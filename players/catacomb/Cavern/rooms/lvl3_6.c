#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  The path through the caves is littered with large rocks shooting up\n"+
"out of the ground.  The echoes from the cavern pervade the area, dripping\n"+
"water from the cavern's moisture can be heard.  The only other sound that\n"+
"can be heard is the crackling of the torches lining the sides of the cavern.\n"+
"The cavern continues to the north and east.\n");

items = ({
  "path",
  "The path leads off to the north and east", 
  "torches",
  "Torches line the sides of the path", 
  "torch",
  "A light source securely fastened to the sides of the path",
  "sides",
  "Torches line the sides of the path",
  "side",
  "Torches line the sides of the path",
  "rock",
  "The rocks jut up out of the ground providing cover for an ambush",
  "rocks",
  "The rocks jut up out of the ground providing cover for an ambush"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_7.c","east",
  "/players/catacomb/Cavern/rooms/lvl3_5.c","north", 
  });
  }

