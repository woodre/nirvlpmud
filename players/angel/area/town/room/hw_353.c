#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "HW 35 race track";
  long_desc =
"    "+HIC+"HW 35"+NORM+"\n\
  Highway 35 strechs 3 miles into Gas City. Gas City's physical\n\
features consist of rolling prairies that drain to the Mississenwa\n\
River, With alluvial soils, and the area is one-fourth forested.\n\
Much of the vegetation consists of cultivated farms and pasture land.\n\
Recreation consists of fishing, hunting, car racing, some historic\n\
sites and a historical museum. The race track to the north. Wal-Mart\n\
distribution center is currently underconstruction to the south and\n\
is closed to thru traffic. They are handing out flier to everyone.\n\
 You can read the flier.\n";

  items =
  ({
  "flier",
"GAS CITY - The official start of construction on Grant\n\
County's Wal-Mart distribution center began the way the\n\
company always kicks off meetings and workdays with a cheer.\n\
Clad in the blue vests familiar to shoppers, a group of\n\
employees from the Wal-Mart Supercenter in Marion filed\n\
to the front of a tent for the ground breaking staked off\n\
the intersection of Ind. 22 and Highway 35 East. Led by that\n\
group, an audience of local and company officials and residents\n\
began to clap their hands and yell",
  "prairie",
  "An area of open rolling grassy land",
  "river",
  "The water is fast flowing and crystal clear",
  "farms",
  "These farms are filled with mile of corn stalks",
  "pasture land",
  "An area of the farm where the cows and pigs live",
  "track",
  "This is a small race track where locals come to\n\
have a bit of fun on the weekend",
  "walmart",
  "A large retailer bent on taking over the world",
  "distribution center",
  "A large building where products are stored and shiped",
  "traffic",
  "It is very busy but you can easily get around",
});
  dest_dir =
  ({
    "/players/angel/area/town/room/hw_352",   "east",
    "/players/angel/area/town/room/hw_354",   "west",
  });
}