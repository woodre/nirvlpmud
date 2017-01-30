/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIB+"Wizard's Hut"+NORM;
    long_desc =
    "The secondary room is quite a bit smaller than the enry room.\n"+
    "There is a large oak bed located near the back wall. In the\n"+
    "corner sits a large red chair that is pointed out towards the window,\n"+
    "next to the chair is a small coffee table where a blue book sits.\n"+
    "A huge chandelier made of marble hangs from the ceiling.\n";

    items =
    ({
    "book",    "A large blue book with tattered edges, it obviously gets a lot of use",
    "table",  "A short round coffee table that stands a few feet off the ground",
    "coffee table",  "A short round coffee table that stands a few feet off the ground",
    "bed",    "A large oak bed, with checker covered sheets",
    "chair",    "A large nice, plush red chair, comfortable looking",
    "chandelier",    "A chandelier made of marble with large beautiful candles",
    "candles",    "A set of unlit candles strategically placed amongst the chandelier",
    "window",   "A great window with a perfect view of a gorgeous rose bush",
    "bush", "There is a bright, beautiful rose bush outside the hut's window",
    "rose bush", "There is a bright, beautiful rose bush outside the hut's window",
    "wall",    "This wall is made of fresh wood, there is still wood shavings and knots in it",
     "room",   "The room is very cozy and comfortable",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/wizhut",        "south",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/wizard.c"), this_object());
    add_smell("main",    "The hut smells fresh and warm, as if it was just cleaned.\n");
    add_sound("main",    "The hut is awfully quiet, it's very peaceful.\n");
    add_feel("chair",    "The chair feels plush and very comfortable.\n");
    add_feel("chandelier",    "The chandelier is just out of your reach.\n");
    add_feel("book",    "The book feels hard cased and you get an uneasy, inadequate feeling when you touch it.\n");
    add_feel("wall",    "The wall is well built and strong.\n");
    add_feel("bed",    "The bed is soft and feels plush.\n");
  }
}
