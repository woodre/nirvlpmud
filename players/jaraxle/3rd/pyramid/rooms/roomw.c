/*  10/06/2006 - Rumplemintz
      Moved inherit above #include statements
*/

inherit "/players/jaraxle/room.c";

#define PATH "/players/jaraxle/3rd/pyramid/rooms/"  /* path of all the rooms */
#include "/players/jaraxle/define.h"

object *rooms;

reset(arg) {


    if(arg) return;
    rooms = ({ "room","room2","room3","roome3" });

    set_light(-1);

    long_desc =
    ""+BLK+""+BOLD+"  The southwest corner of the pyramid is cluttered with broken\n"+
    "crates and piles of rubble.  The walls seem thick, made from\n"+
    "large bricks of clay, which have been deteriorated over time.\n"+
    "Everything in the room is covered in sand. A dry stench fills\n"+
    "the air.\n"+NORM+"";

    items = ({
      "sand", "The cold sand is very smooth to the touch, and light tan in color",
      "pyramid","A large structure made from clay stone",
      "walls","Thick clay walls.\nA lever is sticking out of one of the walls",
      "lever","An old wooden lever",
      "bricks","Large man made bricks of clay",
      "crates","Old wooden crates which have been destroyed with time",
      "rubble","Stacks of broken rock and clay piled around the pyramid",
    });

    dest_dir = ({
      "/players/jaraxle/3rd/pyramid/rooms/room.c","east",
      "/players/jaraxle/3rd/pyramid/rooms/roomw2.c","north",
      "/players/jaraxle/3rd/pyramid/rooms/room2.c","northeast",
    });

}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

init(){
    ::init();
    add_action("pull","pull");
}

pull(arg)
{
    int s, x; /* s is the counter for the inventory of each room,
		 x counts the rooms in the array */
    object room, *inv;

    if(arg == "lever")  /* if arg is correct */
    {
	write("You hear a click as you pull the lever.\n");
	for (x = 0; x < sizeof(rooms); x++) /* for each element.. */
	{
	    room = find_object(PATH + rooms[x]); /* see if the room
						   is loaded */
	    if(!room)  /* if not */
	    { 
		(PATH + rooms[x])->load_me();
		room = find_object(PATH + rooms[x]); /* now grab it ! */
	    }

	    /* dual statement:  s is the size of the array returned
	       by all_inventory() [all objects in the room object
	       are in this array */
	    s = sizeof(inv = all_inventory(room));

	    /* while s ticks down to 0 */
	    while(s--)
		/* if the object we are on in the while() loop
		   is a statue and it's made by jay! */
		if(inv[s]->id("statue") && creator(inv[s]) == "jaraxle")
		{
		    /* dest it */
		    destruct(inv[s]);
		    /* move a defender to its place */
		    move_object(clone_object("/players/jaraxle/3rd/pyramid/mon/defender"),
		      room);
		    /* Add an announcement here ?  tell_room or somethin */
		    tell_room(room,"The statue begins to move!\n");
		}
	}
	/* :) */
	write("The lever moves back to its original position.\n");
	return 1;
    }

    /* added for fun.. notify_fail() lets other objects evaluate
       the verb, but gives a message if no other objects
       can . */
    notify_fail("Type 'pull lever'.\n");
    return 0;
}
