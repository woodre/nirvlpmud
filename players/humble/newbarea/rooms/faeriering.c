/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIM+"Faerie Ring"+NORM;
    long_desc =
    HBBLU+HIM+"Tumbling into a field you notice a large ring of mushrooms that draws\n"+NORM+NORM+
    HBBLU+HIM+"attention. The area is covered with faeries of all colors.\n"+NORM+NORM+
    HBBLU+HIM+"A warm glow is seen as well as felt here. Singing intrudes\n"+NORM+NORM+
    HBBLU+HIM+"your sense. Your vision is blurred by the brightness of\n"+NORM+NORM+
    HBBLU+HIM+"the area. Behind you lies the magical path that took\n"+NORM+NORM+
    HBBLU+HIM+"you here and further ahead, past the faerie ring appears to\n"+NORM+NORM+
    HBBLU+HIM+"to be another field.\n"+NORM+NORM;
    items =
    ({
    "field",   "This is a large field with a ring of mushrooms at the center of it. This is     where the faeries gather at night",
    "mushrooms",    "Pink mushrooms with purple dots all over them, looks very magical",
    "ring",    "A perfect ring of mushrooms",
    "path",    "A enchanted path from which you just came",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/garden3",        "north",
    "/players/humble/newbarea/rooms/path3",        "south",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    add_sound("main",    "You hear strange chanting and singing all around you.\n");
    add_feel("ring",    "The ring feels strange and doesn't feel like it comes from this world.\n");
    add_feel("grass",   "The grass here is soft and makes your skin tingle when you touch it.\n");
    add_feel("mushroom",   "The mushrooms feel soft with a strong consistency, close to that of rubber.\n");
    add_smell("main",    "There is a odd smell here, it's enchanting and soothing.\n");
  }
}
