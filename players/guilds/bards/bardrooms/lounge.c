#include "/players/guilds/bards/bard_lib/lib.h"
#include <ansi.h>
inherit ROOM;

void create() {
	::create();
  set_short(HIM+"The Bard Lounge"+NORM);
  set_long(HIM+
    "The Bard Lounge\n"+NORM+
    "This is a private lounge just for the Bards.  There are\n"+
    "large leather booths lining the walls, with a table between\n"+
    "them.  In the center of the room is a circular booth and a\n"+
    "table it is arrayed around.  On this table is a stone on\n"+
    "which are a list of names of the members of the Bardic Guild\n"+
    "of Ryllian.  To the north is the entrance to the guild.\n"
+"To join the guild, type <"+HIM+"join_bards"+NORM+">.\n"
    );
  set_items(([
    "booths" :
    "Very comfortable leather booths arrayed around tables.\n",
    "table" :
    "Oak tables around which are arrayed booths for seating.\n",
    ]));
  set_smells(([
    "default" :
    "The smell of leather furniture permeates this room.\n",
    ]));
  set_sounds(([
    "default" :
    "Soft harp music plays in the background.\n",
    ]));
  set_exits(([
    "north" : "/players/guilds/bards/bardrooms/enterance",
    ]));
  set_light(1);
  replace_program(ROOM);
}
