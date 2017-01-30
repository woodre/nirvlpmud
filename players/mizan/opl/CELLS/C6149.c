inherit "/players/mizan/opl/core/room.c";
#include "/obj/ansi.h"

object mob0, mob1, mob2, mob3, mob4, bonus, bonus2, bonus3, boss, door1, door2;

/* This is a TOP cell of maze, automatically generated. */
/* Please do not make edits to this file as changes would be overwritten */
/* every two weeks by the Perl code which generates this room. Contact */
/* Mizan directly so he can make changes to the Perl code directly. Thanks! */


reset(int arg)
{
	if(arg) return;

	move_object(this_object(), "/players/mizan/opl/daemons/gridboxDM");
	add_property("fight_area");
	short_desc = "The Proving Grounds of the OverPowerLord";
	dest_dir =
	({
		"/players/mizan/opl/CELLS/C6148", "west",
	});

	/* Our monster list */
	if(!mob0)
	{
		mob0 = clone_object("/players/mizan/opl/beasties/easy/gonk.c");
		move_object(mob0, this_object());
	}

	if(!mob1)
	{
		mob1 = clone_object("/players/mizan/opl/beasties/easy/goliathbeano.c");
		move_object(mob1, this_object());
	}

	if(!mob2)
	{
		mob2 = clone_object("/players/mizan/opl/beasties/easy/gold.c");
		move_object(mob2, this_object());
	}


	custom_exits = 1;
	terrain_icon = BYEL + BLK + "O" + NORM;

	if (!door1)
	{
		door1 = clone_object("/players/mizan/opl/core/door");
		door1->set_dir("down");
		door1->set_door_room("/players/mizan/opl/CELLS/C6149");
		door1->set_type("secpass-a");
		door1->set_code("stonedoor");
		door1->set_door_long("This is a heavy wooden door, several inches thick.\n"+
		                         "There is a note painted in great haste on it reading:\n"+
		                         "    'Keep this closed. Nasty monsters inside.'\n");
		door1->set_locked(1);
		door1->set_closed(1);
		door1->set_can_lock(1);
		door2 = clone_object("/players/mizan/opl/core/door");
		door2->set_dir("up");
		door2->set_door_room("/players/mizan/opl/CELLS/I6149");
		door2->set_type("secpass-a");
		door2->set_code("stonedoor");
		door2->set_door_long("This is a heavy wooden door, several inches thick.\n"+
		                         "It is smeared with layers of caked, dried blood and feces.\n");
		door2->set_can_lock(0);
		door1->set_door(door2);
		door2->set_door(door1);
		move_object(door1, this_object());
		move_object(door2, "/players/mizan/opl/CELLS/I6149");
		door1->set_both_status();
	}

	set_no_clean(1);
}

long()
{
	write("    You are standing on top of a massive stone block, one of many thousands of\n");
	write("which form the sprawing maze that is the Proving Grounds of the OverPowerLord.\n");
	write("There is graffiti on the stone face beneath you. Looking down you see:\n");
	write("\"Bend over for the rod and staff of Jesus!\"\n");
	/* This code generates the top-down map of the room we are in */
	write("    There is one obvious exit: west.\n");

	write(call_other("/players/mizan/opl/daemons/gridDM.c",
	       "render_map",
	       this_object()->query_x(),
	       this_object()->query_y(),
	       this_object()->query_index(),
	       this_object()->query_sight_range() ));

}

query_x() { return 29; }

query_y() { return 51; }

query_index() { return 6149; }

query_sight_range() { return 10; }

query_npc_traversable() { return 1; }
realm() { return "NT"; }

