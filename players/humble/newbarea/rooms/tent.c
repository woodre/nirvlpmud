/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(-1);
    short_desc = HIK+"Dwarf Tent"+NORM;
    long_desc =
    HBRED+"A dark tent that does not seem to be very well lit. There is\n"+NORM+
    HBRED+"a small fire used for cooking meals in the center of the tent.\n"+NORM+
    HBRED+"A cot and large pile of useless linens is tucked away in\n"+NORM+
    HBRED+"the corner. The tent is not very spacious but it serves it's\n"+NORM+
    HBRED+"purpose. It seems to be fit for a well-respected warrior.\n"+NORM;

    items =
    ({
    "cot",    "A large wooden cot that sits in the corner of the tent, used for sleeping",
    "linens",    "Dirty, blood-bathed linens",
    "pile",    "A large pile of dirty, blood-bathed linens",
    "fire", "A small fire used to heat the tent and cook meals",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/garden3.c",        "out",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/bigdwarf.c"), this_object());
    add_feel("cot",   "The cot feels moist.\n");
    add_feel("linens",   "The linens are dry and crusty as if they'd been starched.\n");
    add_feel("pile",     "The pile of linens are dry and crusty, covered in blood.\n");
    add_smell("main",    "The tent smells like cooked goose, blood and ale.\n");
    add_sound("main",    "You hear the wood in the fire turning and popping.\n");
    add_smell("linens",    "The linens smell like blood and urine.\n");
    add_smell("pile",    "The pile of linens smell like blood and urine.\n");
  }
}
