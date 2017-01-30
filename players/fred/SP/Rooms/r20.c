#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
inherit "/players/earwax/housing/land";

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short("South Park");
   set_long(
      "  Inside the trailer park everything is covered in dust from the dirt\n"+
      "road.  Trailers of various sizes seem to be sitting around in no real\n"+
      "order.  Some kids running around in just a diaper are playing chasing\n"+
      "an old cat around the area.\n");

   add_item("road","A dirt road that creates a lot of dust");
   add_item("trailers","Old run down trailers that have seen their better days");
   add_item("kids","Small kids that look like they need a bath.");
   add_item("cat","A large gray cat that is missing part of it's tail.");
   add_smell("main","You take a deep breath and start to cough.....");
   add_listen("main","You hear a loud gunshot followed by someone yelling, \"Woooo eeee!!!!\".");
   add_exit("/players/fred/SP/Rooms/r19.c","south");
   add_exit("/players/fred/SP/Rooms/r22.c","north");
   add_exit("/players/fred/SP/Rooms/r21.c","east");
}
