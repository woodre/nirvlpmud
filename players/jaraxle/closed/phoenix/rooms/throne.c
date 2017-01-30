#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";
realm() { return "NT"; }


reset(arg) {
   if(arg) return;
   add_property("no_follow");
   set_light(1);
   short_desc = "Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM+"("+HIC+"Throne Room"+NORM+")";
   long_desc =
   "  A large room with a marble laid floor and four\n"+
   "huge pillars towards each corner.  Towards the\n"+
   "center of the room in the back is a massive\n"+
   "throne.  Tapestries hang from the white stone\n"+
   "walls.  Two wide oil bowls sit towards the sides\n"+
   "of the room lighting the area.\n";
   add_item("floors","Floors made with large squares of gray and black marble");
   add_item("marble","Italian imported marble");
   add_item("pillars","Large circular pillars from the ground reaching up to the ceiling");
   add_item("throne","A massive throne of dark wood. Bands of gold\nare wrapped around each joint");
   add_item("walls","Walls made of white stone");
   add_item("tapestries","Large tapestries of bright red and purple");
   add_item("bowls","Large copper bowls full of oil. Bright fire\nburns hot in each one, lighting the room");
   add_object("/players/jaraxle/closed/phoenix/mons/lord.c");
   add_exit("/players/jaraxle/closed/phoenix/rooms/floor2c.c","leave");
}

init(){
   ::init();
   add_action("leave_block","leave");
}

leave_block(){
   if(present("vulpine lord",environment(TP)) && TP->query_money() > 10000){
      write("The Vulpine Lord commands, 'If you want to leave my lair, you must'\n"+
         "\tleave behind more coins on the ground for me.'\n");
      return 1; }
}
