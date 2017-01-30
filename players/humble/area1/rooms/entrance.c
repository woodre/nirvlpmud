
/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Code*/
#include "/obj/ansi.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIR+"Swirling Gateway"+NORM;
    long_desc = (
    "As you enter "+MAG+"Humble's Realm"+NORM+" you notice the vast\n"+
    "amount of "+HIY+"Sand"+NORM+" swirling all about at devastating\n"+
    "speeds. The chaotic storm beats against your skin, infiltrating\n"+
    "your every orifice. Scanning the area you find a "+HIK+"hole"+NORM+" within\n"+
    "the storm to your left. To your right you spot a "+HIC+"tear"+NORM+" inside\n"+
    "the Vortex.  This world you've stepped into is immense. There\n"+
    "is quite a lot of electrical activity above your head which is in\n"+
    "someway tied together with all the gusting winds and current\n"+
    "whirling Storm.\n"+
    HIR+"You fear for your life.\n"+NORM);

    items =
    ({
    "sand", "There are countless specks of sand flying about at blurring speeds",
    "storm", "You are stuck inside a vortex, there is a large electrical\n"+
    "storm occuring that is feeding a horrendous Sandstorm",
    "vortex", "A large vortex between this realm and another.\n"+
    "Sand swirls all about, irritating your skin.\n"+
    "Overhead "+BLU+"lighting"+NORM+" strikes down all about the land",
        "hole",
    "Before you appears a hole you can enter.\n"+
    "inside the hole you can see a busy parking lot",
    "lightning", "Lighting cause by the large electrical storm",
    "sandstorm",  "You stand in the center of a large Sandstorm",
    "tear",  "A small tear inside the vortex, perhaps you can "+HIW+"enter"+NORM+" it?",
    });
    dest_dir =
    ({
    "/room/south/sforst13.c",        "back",
    });
  }
}

  init() {
      ::init();

    add_action("enter","enter");
}
    enter(arg)
{
    if(arg != "hole" && arg != "tear")
  {
    notify_fail("What are you trying to enter?\n");
    return 0;
  }
    if(arg == "hole")
  {
    write("This area is not open yet, come back later.\n");
    return 1;
  }
    if(arg =="tear")
  {
    write("You step into the tear and pop out into a garden.\n");
    say(capitalize(this_player()->query_name())+" steps into the tear in the world.\n");
    move_object(this_player(),"/players/humble/newbarea/rooms/garden1.c");
    command("look", this_player());
    return 1;
  }
}
