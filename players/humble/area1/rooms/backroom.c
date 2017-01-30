 /* COPYRIGHT (C) VITAL CORP, outline derived from Vital Code */

#include "../defs.h"
int freezer;
int backdoor;
inherit "room/room";

reset(arg) {
    freezer = 0;
    backdoor = 0;
  if(!arg)
  { 
    set_light(1);
    short_desc = CYN+"Backroom"+NORM;
    long_desc =
    "This is the backroom.  There are enormous rafters containing\n"+
    "pallets of grocery backstock along with beer and soda boards.\n"+
    "Off to the left of the rafters is a large"+HIW+" grey door"+NORM+" .\n"+
    "Across from the grey door is a large desk with a computer mounted atop it.\n"+
    "There is an enormous "+GRN+"backdoor"+NORM+" here, much like a garage door.\n"+
    "In front of the huge garage door is a forklift.  To the right of the forklift\n"+
    "There is a set of double doors much like the ones you came in.\n"+
    "Above the double doors there is a sign that reads "+HIB+" Dairy Cooler.\n"+NORM;
    "pallets of grocery backstock along with beer and\n"+
    "soda boards.  Off to the left of the rafters is a large\n"+
    "grey door with a huge handle on it.  Across from that\n"+
    "is a large desk with a computer mounted atop it.\n"+
    "There is a large backdoor here, much like a garage\n"+
    "door.  In front of the huge garage door is a forklift.\n"+
    "Nearby the computer is another set of doors\n"+
    "similar to the doors you entered to get here.\n";

    items =
    ({
    "pallets","Enormous pallets of backstock items",
    "pallet","A pallet filled with beer, mmmmmm beer",
    "backdoor","A huge backdoor that is basically a garage door, there is a latch on the side of it",
    "latch","Maybe you could open the "+HIW+" backdoor !?"+NORM,
    "desk","This is Debbie's receiving desk",
    "computer","This processes orders, invoices and deleveries",
    "door","By the touch of this huge door you'd say it was the "+HIB+"Freezer"+NORM,
    "grey door","By the touch of this huge door you'd say it was the "+HIB+"Freezer"+NORM,
    "freezer","You could open the freezer door.\n"+NORM,
    "doors","This is a set of doors leading into the dairy",
    "dairy cooler","Perhaps you could enter the "+HIW+"Dairy?\n"+NORM,
    "dairy","Perhaps you could enter the "+HIW+"Dairy?\n"+NORM,
    "cooler","Perhaps you could enter the "+HIW+"Dairy?\n"+NORM,
    "rafters","Huge rafters from floor to ceiling containing pallets of things you see in a backroom",
    "beer","Miller Light, Coors Light, HG-800 Malt Liquor, shit, I could go on all day",
    "soda","Pepsi and Coca-Cola products",
    "backstock","Boards of grocery backstock",
    });
    dest_dir =
    ({
    RPATH+"aisle12",        "leave",
    });

    move_object(clone_object("players/humble/area1/mobs/debbie.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/mark.c"), this_object());
  }
}

init()
{
    ::init();
    add_action("open","open");
    add_action("enter","enter");
}

    open(arg) {

    if(!arg || arg == "") {
      notify_fail("What do you want to open?\n");
      return 0;
    }

    if (arg =="freezer") { freezer = 1;
    write("You pull the huge handle towards you and the enormous door slides open.\n");
    say(capitalize(this_player()->query_name())+" pulls open the freezer.\n");
    return 1;
    }

    if (arg =="backdoor") { backdoor = 1;
    write("You slide the latch over and push up the huge back door revealing the loading dock.\n");
    say(capitalize(this_player()->query_name())+" does something with the backdoor and it slides up revealing the outside world.\n");
    return 1;
    }
}

    enter (arg) {

    if(!arg || arg == "") {
    notify_fail("What are you trying to enter?\n");
    return 0;
    }

    if(arg == "freezer") {
    if(!freezer == 1) {
    notify_fail("Try opening it? Duh!\n");
    return 0;}
    this_player()->move_player("enter#/players/humble/area1/rooms/freezer.c");
    write("You step into the freezer, hope you brought a coat.\n");
    say(capitalize(this_player()->query_name())+" disappears into the freezer.\n");
    return 1;
    }

    if(arg =="backdoor") {
    if(!backdoor ==1) {
    notify_fail("Why did you just run into the backdoor?\n");
    return 0;}
    this_player()->move_player("enter#/players/humble/area1/rooms/dock.c");
    write("You go out to play on the loading dock.\n");
    say(capitalize(this_player()->query_name())+" runs out onto the loading dock.\n");
    return 1;
    }

    if(arg =="dairy") {
    this_player()->move_player("enter#/players/humble/area1/rooms/dairy.c");
    write("You push the set of doors open and enter the cooler.\n");
    say(capitalize(this_player()->query_name())+" disappears into the dairy cooler.\n");
    return 1;
    }
}
