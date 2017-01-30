#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"CRaZed FoReSt"+NORM);
   set_long(
      "  You know stand in one of the larger rooms in the den. Light\n"+
      "shines visibly through a small hole in the ceiling leading to\n"+
      "the outside. A large ledge is noticable above you. The wall\n"+
      "leading up to it has small grooves in it making it possible to\n"+
      "climb.\n");
   add_item("den","A large den of unknown origin");
   add_item("light","Sunlight from the outside world, it is warm and comforting");
   add_item("hole","A small hole that allows light to shine into the room");
   add_item("ledge","A large ledge made of solid stone");
   add_item("ceiling","The ceiling is made of rock and has moisture forming on it");
   add_item("walls","Rough textured walls formed out of stone");
   add_item("grooves","Small grooves that would be great footings");
   add_listen("main","Strange rustling noises fill the room.");
   add_exit("/players/fred/forest/Rooms/forest37.c","west");
   add_exit("/players/fred/forest/Rooms/forest38.c","climb");
   set_chance(3);
   add_msg("You feel something brush against your leg...\n");
   add_msg("The hairs on your neck stand on end...\n");
   add_object("/players/fred/forest/Mon/ferret.c");
}

