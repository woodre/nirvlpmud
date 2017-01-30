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
	set_map_filename("level03_superbunker");
	set_spawn_point(63);
	set_cell_short_desc(HIY + "[3]" + NORM + " Inside the Earwaxian Superbunker");
	set_cell_long_desc(

  "    The claustrophobic environment of this dirt-walled bunker makes you\n"+
  "  very uneasy. It's not so much the acrid urine and fecal smell, it's the\n"+
  "  noises and screaming that you hear in the background. Everything in here\n"+
  "  seems to be either in a state of pain, suffering, intimate misery, or a\n"+
  "  varied combination of the three.\n"

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

	add_cell_portal("You see a stairway headed up, back to the tublock area.", "/players/mizan/mines/ROOMS/L03/ewbunker_entrance.c", "up", "down", 0, 1);	

	add_cell_portal("You see a dirt-walled hole which you can 'enter'.", "/players/mizan/mines/ROOMS/L03/ewbunker_corridor.c", "down", "up", 63, 1);

}

