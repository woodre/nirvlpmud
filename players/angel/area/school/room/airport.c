#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Gas City";
  long_desc =
"  Welcome to Gas City Airport. It's a small quaint airport\n\
that uses small planes and helicopters to transport people\n\
around the city. The small planes go to the city and the\n\
helicopters are used to get around the different areas of\n\
the city. Westview Elementary school, Wal-Mart, Colony Way\n\
subdivision, amd the pub are currently open but the rest of\n\
Gas City in under construction.\n";

  items =
  ({
    "Gas City",
    "A very prosperous town that is built along the Scenic\n\
Mississinewa River, which foster growth and security. It\n\
is a quaint, quiet, safe, secure and friendly town to over\n\
8000 people. This town is strategically located along the\n\
I-69 corridor.",
    "river",
    "It is a nice flowing river. Many people like to tube down it\n\
in the summer.",
    "river",
    "It is a nice flowing river. Many people like to tube down it\n\
in the summer.",
    "i-69",
    "a corridor that the federal government wants to extend from\n\
Indiana to Texas",
    "town",
    "A place where people live, it is lively", 
    "airport",
    "This is a small airport with one run way and 4 heli pads",
  });
  dest_dir =
  ({
	"/players/angel/area/stargate/room/sg1",                "stargate",  
    "/players/angel/area/school/room/entrance",             "school",
    "/players/angel/area/walmart/room/walmart_checkout",    "walmart",
    "/players/angel/area/town/room/4thnh",                  "colony",
    "/players/angel/masons/room/pub.c",                     "pub",
/*  "/players/angel/area/town/room/foyer.c",                "fly",  */
  });
}

init() {
  ::init();
    add_action("fly","fly");
} 

fly() {
    if (call_other(this_player(), "query_level", 0) < 20) {
        write("A strong magic force stops you.\n");
        say(call_other(this_player(), "query_name", 0) +
            " tries to go through the field, but fails.\n");
        return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "fly#/players/angel/area/town/room/foyer.c");
    return 1;
}
