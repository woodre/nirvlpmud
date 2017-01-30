inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("shirley", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/shirley.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = "A "+HIW+"Quiet"+HIC+"Pond"+NORM;
  long_desc = " A small beautiful crystal blue pond. It has Cat tails and Reeds all \n\
  around the edges of the bank. Fish of all types can be seen swimming\n\
  at the bed of the lake. Seaweed and rocks of all shapes and sizes fill the\n\
  bed of the lake. Lilly pads float all around the surface of the lake. Frogs\n\
  and all types of insects echo noise through the air.\n";
  items = 
  ({
    "reeds",
    "normal reeds that grow around the lake",
    "frogs",
    "little green frogs that hop from one pad to another",
    "rocks",
    "small rocks that are at the bottom of the lake",
    "pond",
    "A crystal clear blue pond with fish swimming in it",
    "fish",
    "Fish of all shapes and sizes swimming in the pond",
    "lilly",
    "Small lilly pads that float along the top of the pond water",
    "insects",
    "Mosquitoes and all kinds if irritating insects buzz around the pond",
    "tails",
    "Cat tails that grow tall around the pond swaying in the wind",
  });
   dest_dir=({
  "/players/wicket/tv/looney/rooms/pluckyhouse.c","north",
  "/players/wicket/tv/looney/rooms/toonroad2.c","west",
  });
  }