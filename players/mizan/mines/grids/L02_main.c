inherit "/players/mizan/mines/daemons/gridDM.c";
#include "../definitions.h"
#include "/obj/ansi.h"


short() { return "A server named (l2rdm)"; }
id(str) { return str == "l2rdm" || str == "server"; }

int my_hole01;
int my_hole02;
int my_hole03;
int my_hole04;
int my_hole05;
int my_hole06;

reset(arg)
{
	/* move ourselves home. */
	move_object(this_object(), DAEMON_HOME);

	/* This MUST be called first */
	set_map_filename("level02");
	set_spawn_point(1);

	set_cell_short_desc(HIY + "[2]" + NORM + " Torgo's Weasel Farm");
	set_cell_long_desc(
  "    Inside this great chamber underground is a grassy knoll that is lit\n"+
  "  by intensely bright artificial lighting hanging far above the ground.\n"+
  "  While it is similar to the bunny chamber, it seems to be significantly\n"+
  "  less sanitary, and definitely less professionally maintained. This might\n"+
  "  have something to do with the sloppy management style of the weasel farm.\n"
	);
	set_monster_load("/players/mizan/mines/beasties/L02/weasel.c", 1, 80);

	/* The superclass must be called last */
	::reset(arg);
}

extra_reset()
{
	::extra_reset();

	my_hole01 = random(4) + 19;
	my_hole02 = random(3) + 24;
	my_hole03 = random(6) + 31;
	my_hole04 = random(4) + 55;
	my_hole05 = random(4) + 67;
	my_hole06 = random(10) + 84; 

	add_cell_portal("You see a stairway headed up, back to the tublock area.", "/players/mizan/mines/ROOMS/entrance02.c", "up", "down", 1, 1);	
	add_cell_portal("You see a gritty hole in the ground which you can 'enter'.", "/players/mizan/mines/ROOMS/L02/hole01.c", "enter", "out", my_hole01, 1);
	add_cell_portal("You see a gritty hole in the ground which you can 'enter'.", "/players/mizan/mines/ROOMS/L02/hole02.c", "enter", "out", my_hole02, 1);
	add_cell_portal("You see a gritty hole in the ground which you can 'enter'.", "/players/mizan/mines/ROOMS/L02/hole03.c", "enter", "out", my_hole03, 1);
	add_cell_portal("You see a gritty hole in the ground which you can 'enter'.", "/players/mizan/mines/ROOMS/L02/hole04.c", "enter", "out", my_hole04, 1);
	add_cell_portal("You see a gritty hole in the ground which you can 'enter'.", "/players/mizan/mines/ROOMS/L02/hole05.c", "enter", "out", my_hole05, 1);
	add_cell_portal("You almost missed it, you're right on top of a hole which you can 'enter'.", "/players/mizan/mines/ROOMS/L02/hole06.c", "enter", "out", my_hole06, 0);
}

