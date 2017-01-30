#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Colony Way Subdivision"+NORM;
  long_desc =
"  This is the biegining of Colony Way Subdivision. The road curves\n\
around several time. This is where the rich and powerful reside.\n\
There are several large homes and a couple that qualify as mansions.\n\
All of the lawns are perfectly manicured and the air smells of fresh\n\
cut grass.\n";

  items =
  ({
  "road",
  "It is a concrete paved road, top of the line.",
  "home",
  "There are several family structures of high quality\n\
and workmanship.",
  "homes",
  "There are several family structures of high quality\n\
and workmanship.",
  "mansion",
  "This is a large and stately dwelling house built in a\n\
completely gracious style, with gardens, parks and drives.\n\
It is comprised four wings in a square surrounding a central\n\
courtyard.",
  "mansions",
  " These are large and stately dwelling houses built in a\n\
completely gracious style, with gardens, parks and drives.\n\
Many are comprised four wings in a square surrounding a central\n\
courtyard.",
  "grass",
  "This is narrow-leaved green herbage grown as lawns.",
  "lawn",
  "A plot of grass, usually tended or mowed, as one around\n\
a resident estate.",
  "lawns",
  "Plots of grass, usually tended or mowed, as one around\n\
a residence or in a park or estate.",
  "subdivision",
  "This is an area of land composed of subdivided lots",
});

  dest_dir =
  ({
"/players/angel/area/town/room/colony_02", "north",
"/players/angel/area/town/room/4thnh", "south",
"/players/angel/area/town/land/land_09", "222colony",
"/players/angel/area/town/land/land_10", ""+"221 colony"+"",
  });
}
