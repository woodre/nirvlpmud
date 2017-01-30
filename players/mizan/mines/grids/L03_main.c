inherit "/players/mizan/mines/daemons/gridDM.c";
#include "../definitions.h"
#include "/obj/ansi.h"

short() { return "A server named (l3rdm)"; }
id(str) { return str == "l3rdm" || str == "server"; }


reset(arg)
{
	/* move ourselves home. */
	move_object(this_object(), DAEMON_HOME);

	/* This MUST be called first */
	set_map_filename("level03");
	set_spawn_point(59);
	set_cell_short_desc(HIY + "[3]" + NORM + " Commando Sheep Country");
	set_cell_long_desc(
  "    You are somewhat disoriented, even though this is not the first large\n"+
  "  underground chamber of its kind that you have seen... but being in an\n"+
  "  artificially lit countryside that might be thousands of feet underground\n"+
  "  still feels really... strange. A river bisects the two lands before you,\n"+
  "  and you notice that the area to the east is barren and parched. Something\n"+
  "  rather screwy is going on in this part of the world. Tread with care.\n"
	);
/*
	set_monster_load("/players/mizan/mines/beasties/L03/sheep.c", 4, 30);
*/
	/* The superclass must be called last */
	::reset(arg);
}

extra_reset()
{
	::extra_reset();

	add_cell_portal("You see a stairway headed up, back to the tublock area.", "/players/mizan/mines/ROOMS/entrance03.c", "up", "down", 2, 1);	

	add_cell_portal("You see a dirt hole which you can go 'down' into.", "/players/mizan/mines/ROOMS/L03/ewbunker_entrance.c", "down", "up", 59, 1);

}

