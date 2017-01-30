#include <ansi.h>
#include "/players/guilds/bards/bard_lib/lib.h"
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {
	::create();

  set_short(HIM+"Bard Teleport Chamber"+NORM);
  set_long(HIM+
    "Bard Teleport Chamber\n"+NORM+
    "This chamber is constructed entirely from polished mahogany\n"+
    "wood.  The room is bare.  The only object of interest is the\n"+
    "circle of blue power floating seven inches off the floor,\n"+
    "just large enough for one person to sit in.  The room is\n"+
    "illuminated dimly by the aura from the "+BLU+"blue circle"+NORM+".\n"+
    "You can leave north to the song room, south to the central\n"+
    "guild room and west to the pool.  The exits through the portal\n"+
    "are 'church' to go to the village church and 'portal' to enter\n"+
    "the chamber of realms.  The Guild Commander room is to the east.\n"
    );
  set_items(([
    "floor" :
    "The floor is made from a beautiful mahogany wood.\n",
    "circle" :
    "A "+BLU+"blue circle"+NORM+" of power hovers seven inches off the"+
    " wooden floor.\n"+
    "It is just large enough for a person to sit in.\n",
    "aura" :
    "The blue circle of power glows faintly.\n",
    ]));
  set_smells(([
    "default" :
    "The faint smell of ozone permeates this room.\n",
    ]));
  set_sounds(([
    "default" :
    "A slight humming can be detected from the circle.\n",
    ]));
  set_exits(([
    "north" : "/players/guilds/bards/bardrooms/songs",
    "south" : "/players/guilds/bards/bardrooms/common",
    "west" : "/players/guilds/bards/bardrooms/advance",
    "east" : "/players/guilds/bards/bardrooms/gcroom",
    "portal" : "/players/saber/ryllian/portal",
    "church" : "/room/church",
    ]));
  set_light(1);
  replace_program(ROOM);
}
