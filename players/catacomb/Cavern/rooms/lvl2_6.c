#include "/players/catacomb/misc/ansi.h"
#define TPN this_player()->query_name()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  Small creatures scatter from the light, finding security in\n"+
  "the shadows of the many large rocks throughout the cavern.  The\n"+
  "torches cast strange looking shadows about the area.  With every\n"+
  "flicker of the torch a new shadow is born and another one dies. \n"+
  "Loud screeches can be heard to the southwest. \n"); 

  items = ({
    "creatures",
    "Small creatures scurry from the light the torches give off",
    "creature",
    "A small bug runs behind a rock to get out of the sight of a would-be predator", 
    "bugs",
    "Small bugs scurry from the light the torches give off", 
    "bug",
    "A small bug runs behind a rock to get out of the sight of a would-be predator",
    "rocks",
    "The rocks house many hiding bugs",
    "rock",
    "A single rock is decorated in the blood of the fallen",
    "torches",
    "The torches cast strange shadows throughout the cavern",
    "torch",
    "The torch crackles on the side of the cavern",
    "shadow",
    "The shadows almost seem to have a life of their own",
    "shadows",
    "The shadows almost seem to have a life of their own"
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_7.c","east",
    "/players/catacomb/Cavern/rooms/lvl2_8.c","southwest"
  });

if(!present("maijan"))
{
    move_object(clone_object("/players/catacomb/Cavern/mobs/maijan.c"),
	  this_object());
    move_object(clone_object("/players/catacomb/Cavern/mobs/maijan.c"),
	  this_object());
}
}

init()
{
  ::init();

  add_action("hear","listen");
}

hear(str)
{
  write("You can hear the loud screeches of something from the southwest.\n");
  say(TPN+" listens to the loud screeches of something to the southwest.\n");
  return 1;
}
