
/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Code*/
#include <ansi.h>

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIR+"Swirling Gateway"+NORM;
    long_desc =
    "As you enter "+MAG+"Humble's Realm"+NORM+" you notice the vast\n"+
    HIR+"Storm"+NORM+" swirling all about you. There is an enormous\n"+
    "amount of "+HIY+"Sand"+NORM+" whirling about the room at devastating\n"+
    "speeds. As you peer about the chaotic storm sand begins to beat against\n"+
    "your skin, causing you to cover your face quickly.  You peek about\n"+
    "briefly, scanning this strange world for an exit.\n"+
    "Your eyes catch a hole in the "+HIR+"Storm"+NORM+" to \n"+
    "your left.  Inside the hole you catch a glimpse of a parking lot.\n";

    items =
    ({
        "sand",
        "There are countless specks of sand flying about at blurring speeds",
        "storm",
    "There is a large "+HIB+"electrical"+NORM+" storm occuring about you.\n"+
    "Sand swirls all about, irritating your skin.\n"+
    "Overhead "+BLU+"lighting"+NORM+" strikes down all about the land",
        "hole",
    "Before you appears a hole you can enter.\n"+
    "Inside the hole you spot a busy parking lot.",
    });
    dest_dir =
    ({
    "/players/humble/area1/rooms/lot.c",        "enter hole",
    "/room/south/sforst13.c",        "back",
    });
  }
}

    init() {
    ::init();

   add_action("enter_me","enter");
}

   enter(arg){
    if(arg! = "hole") {
    notify_fail("Enter what?\n");
    return 0;

    write("You enter a hole.");

    say(capitalize(this_player()->query_name())+" enters a hole.\n");
    move_object(this_player(),"/players/humble/area1/rooms/lot.c");
    return 1;
   }
