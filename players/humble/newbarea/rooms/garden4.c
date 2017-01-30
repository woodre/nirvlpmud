/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIG+"Enchanted Garden"+NORM;
    long_desc =
    HBGRN+"The path ends and a large garden is seen here.  Towards the back\n"+NORM+
    HBGRN+"of the garden is a strange brown hut.  The garden seems to glow here\n"+NORM+
    HBGRN+"more than it does in any part of the enchanted area.  A vibrant\n"+NORM+
    HBGRN+"force is felt and seems to be coming from the hut. Everything within\n"+NORM+
    HBGRN+"the surrounding area seems so alive and fresh.\n"+NORM;

    items =
    ({
    "path",   "The path is a dark orange almost red color and winds throughout the woods",
    "garden", "A long garden, everything is bright, vibrant and aesthetically pleasing here",
    "hut",    "A large hut, with a big brown oak door. Perhaps you could enter it?",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/path6",        "south",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/sprites.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/sprites.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/largeelf.c"), this_object());
    add_smell("main",    "It smells clean here, a strange smell fills the air.\n");
    add_sound("main",    "There is a melodic humming coming from inside the hut.\n");
    add_feel("hut",    "The hut is hard wood, it's warm and familiar when you touch it.\n");
    add_feel("garden",    "You bend down and touch the grass, it's soft but dry.\n");
  }
}

    init() {
      ::init();
      add_action("enter", "enter");
}

    enter(arg) {

      if(arg !="hut") {
      notify_fail("What do you want to enter?\n");
    return 0;
}

    write("You open the door and step inside the hut.\n");
    say(capitalize(this_player()->query_name())+" opens the door and steps into the hut.\n");
    move_object(this_player(),"/players/humble/newbarea/rooms/wizhut.c");
    command("look", this_player());
    return 1;
}
