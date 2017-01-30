/**
 * This daemon is responsible for maintaining the entry and exit rooms for
 * each of the self-contained levels. It is basically a one-dimensional
 * room array, with the easiest levels at the top and the harder ones the
 * deeper down you go.
 *
 * Another future responsibility of this file is to act like an entrance
 * barrier which does not let players into the realm until it is completed
 * loading.
 *
 */
#include "../definitions.h"
#define MAX_DEPTH 40

string *my_names;

int get() { return 0; }
string short() { return "A server named (tublock)"; }
int id(string str) { return str == "tublock" || str == "server"; }

string *rooms;

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);
    rooms = allocate(MAX_DEPTH);

    remove_call_out("generate_rooms");
    call_out("generate_rooms", 1);
}

/* Externally available. */
/* This method returns the index number of the room for that given level. */
mixed get_tublock_room(int arg)
{
	if(arg && arg >= 0 && arg < MAX_DEPTH)
		return rooms[arg];
	else return 0;
}

/* We wait a second before kicking this off to generate all the rooms */
void generate_rooms()
{
	int i;
	object ob;
	string temp;


	/* Two loops. First we generate all the room objects */
	for(i = 0; i < MAX_DEPTH; i ++)
	{
		ob = clone_object("/players/mizan/mines/core/tublock.c");
		rooms[i] = object_name(ob);
	}

	/* Now we populate them with data. */
	for(i = 0; i < MAX_DEPTH; i ++)
	{
		ob = find_object(rooms[i]);

		/* tell_object(find_player("mizan"), rooms[i] + "\n"); */

		ob->set_minimum_level(i + 1);
		ob->set_short("Tublock " + (i + 1));

		temp = "This is Tublock " + (i + 1) + "\n";
		/* 
		temp+= "It is tentatively known as '" + LEVEL_DM->get_level_name(i) + "'.\n";
		*/

		ob->set_long(temp);
		
		/* now we set exits on the rooms */

		if(i == 0) /* at the first tublock */
		{
			ob->add_exit("/players/mizan/mines/ROOMS/entrance.c", "up");
			ob->add_exit(rooms[i + 1], "down");
			"/players/mizan/mines/ROOMS/tublock01.c"->add_exit(rooms[0], "down");

		}
		else if(i == (MAX_DEPTH - 1)) /* at the end */
		{
			ob->add_exit(rooms[i - 1], "up");
		}
		else /* and now every one in between */
		{
			ob->add_exit(rooms[i - 1], "up");
			ob->add_exit(rooms[i + 1], "down");
		}
	}
}

