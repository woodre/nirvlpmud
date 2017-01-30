#include "/players/fred/ansi.h" 
inherit "/players/vertebraker/closed/std/room";
inherit "/players/earwax/housing/land";

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"CRaZed FoReSt"+NORM);
   set_long(
      "  A large open area nestled next to a shimmering pond.  The pond\n"+ 
      "is clean and clear with some odd looking fish swimming in it.  Several\n"+
      "large sycamore trees stretch towards the sky providing a lot of shade.\n");

   add_item("pond","A large pond filled with fish!");
   add_item("trees","Large white sycamore trees");
   add_item("fish","Small strange looking fish that dart away when they notice you");
   add_item("area","A beautiful open an area surrounded by large trees");
   add_smell("main","What is that smell is that.....peanutbutter??");
   add_listen("main","You hear some birds chirping off in the distance.");
   add_exit("/players/fred/forest/Rooms/forest21.c","east");
   
   
   /* For Waxy's Land Development */
   
   set_cost(180000);
   set_realm_name("CRaZed FoReSt");
   set_lot_size("6"); /* house, cottage */
   setup_land();
}
