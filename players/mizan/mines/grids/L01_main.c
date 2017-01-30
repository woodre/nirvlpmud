inherit "/players/mizan/mines/daemons/gridDM.c";
#include "../definitions.h"
#include "/obj/ansi.h"


short() { return "A server named (l1rdm)"; }
id(str) { return str == "l1rdm" || str == "server"; }

int my_hovel;

reset(arg)
{
	/* move ourselves home. */
	move_object(this_object(), DAEMON_HOME);

	/* This MUST be called first */
	set_map_filename("level01");
	set_spawn_point(my_hovel);

	set_cell_short_desc(HIY + "[1]" + NORM + " De Grassi Knoll");
	set_cell_long_desc(
  "    Inside this great chamber underground is a grassy knoll that is lit\n"+
  "  by intensely bright artificial lighting hanging far above the ground.\n"+
  "  The knobbly grass field before you is invariably covered with holes\n"+
  "  and burrows from the local bunny infestation. Perhaps you should help\n"+
  "  yourself to killing whatever is available.\n"
	);
	set_monster_load("/players/mizan/mines/beasties/L01/bunny.c", 4, 30);

	/* The superclass must be called last */
	::reset(arg);
}

extra_reset()
{
	::extra_reset();

	my_hovel = random(3) + 44;

	add_cell_portal("You see a stairway headed up, back to the tublock area.", "/players/mizan/mines/ROOMS/entrance01.c", "up", "down", 1, 1);	
	add_cell_portal("You see a dirt-walled hovel which you can go 'down' into.", "/players/mizan/mines/ROOMS/L01/hovel.c", "down", "up", my_hovel, 1);
}

