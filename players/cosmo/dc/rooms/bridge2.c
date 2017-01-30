#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h"
inherit "room/room";
int lion_test;

reset(arg) {
    if (arg) return;
    lion_test = 0;
    set_light(1);
    short_desc = MAG+"Memorial Bridge"+NORM;
    no_castle_flag = 0;
    long_desc = 
         "   As you begin to walk across the Potomac River on this short narrow\n"
        +"bridge, you pass two gold lions' head statues on each side of\n"
        +"the bridge entrance.  Across the bridge, the vast city of\n"
        +"Washington D.C. stands before you; however, much of the skyline\n"
        +"is blocked by the majestic "+BLU+"Lincoln Memorial"+NORM+" on"
 	+" the other side\nof the bridge.\n\n";

    items = ({
        "river", "A filthy polluted river.  Who knows what's down there",
        "bridge", "An old narrow bridge with 1 lane of traffic in each direction",
        "memorial", "The Lincoln lies ahead on the other side of the bridge",
        "statues", "The gold lions seem almost life-like",
    });

    dest_dir = 
        ({
        DCDIR+"rooms/srcp1", "city",
        DCDIR+"rooms/entrance", "back",
    });
}

init() {
   ::init();
   add_action("touch","touch");
   add_action("city","city");
}

touch(arg) {
   if(!arg) {
      write("What would you like to touch?\n"); return 1; }
   if (lion_test != 0) {
      write("The statues have already been touched.\n");
      return 1;}

   if(arg == "lions" || arg == "statue" || arg == "statues") {
      write("As your fingers touch the cold stone statues, the lions are suddenly");
      write(" infused with life and spring down to the ground.\n");
      say(capitalize(TPQN)+" reaches out and touches the gold statues.\n");
      lion_test = 1;
      move_object(clone_object("/players/cosmo/dc/mon/lion.c"), this_object());
      move_object(clone_object("/players/cosmo/dc/mon/lion.c"), this_object());
   return 1; }
   else {
      write("You touch the golden statues, but nothing happens.\n");
   return 1; }
}

city() {
   if(present("lion", this_object())) {
      write("The lion blocks your path.\n");
   return 1; }
   else {
      TPMP("cross#/players/cosmo/dc/rooms/srcp1.c");
   return 1; }
}
