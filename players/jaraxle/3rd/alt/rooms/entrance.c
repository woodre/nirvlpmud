#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_no_clean(1);
   add_property("no_fight");
   add_property("no_magic");
   set_light(0);
   short_desc = "Third Earth "+HIW+"["+BLK+BOLD+"shadows"+HIW+"]"+NORM+"";
   long_desc =
   "  A small dank meadow in the pitch darkness of the forest.\n"+
   "There is no grass here, the trees look petrified and\n"+
   "alive.  Living shadows dance over the moist dirt as the\n"+
   "air howls through the room [moving nothing].\n";
   add_item("trees","Dark wooden trees growing around the meadow");
   add_item("shadows","Shadows pulling at the base of trees.\nYou notice a strange vortex in the background");
   add_item("vortex","A swirling vortex of mist and shadow");
   add_object("/players/jaraxle/3rd/alt/mobs/guard.c");
   add_exit("/players/jaraxle/3rd/warrior/rooms/room3.c","southwest");
}


init(){
   ::init();
   add_action("enter","enter");
}

enter(str){
   if(!str) return (notify_fail("What?\n"), 0);
   if(str == "shadow" || str == "vortex"){
      write("You enter the vortex through to another realm.\n");
      TP->move_player("into the shadows#/players/jaraxle/3rd/alt/rooms/church.c");
      say("Appears out of a swirling vortex.\n");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }
