#include "std.h"
#define CASINO "players/boltar/casino/"
#define STILL	0
#define DOWN	1
#define UP	2

int level;
string levelrm;
int door_is_open;
int time_to_close_door;
int dest;		/* Where we are going. */
int moving_time;	/* How long we are going to move. */
int delay_to_reset;	/* Move back to origin automatically after a delay. */

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("press"); add_verb("press");
    add_action("press"); add_verb("push");
    add_action("open_door"); add_verb("open");
    add_action("close_door"); add_verb("close");
    add_action("go_west"); add_verb("west");
#else
  add_action("press", "press");
  add_action("press", "push");
  add_action("open_door", "open");
  add_action("close_door", "close");
  add_action("go_west", "west");
#endif
}

short() {
    return "elevator";
}

reset(arg) {
    door_is_open = 0;
    levelrm=allocate(6);
    levelrm[1]=CASINO+"hall1e1";
    levelrm[2]=CASINO+"hall2x1";
    levelrm[3]=CASINO+"hall3x1";
    levelrm[4]=CASINO+"hall4x1";
    if (arg)
	return;
    set_light(1);
    level = 1;
    dest = 1;
    moving_time = 0;
}

/*
 * Return true if closed door.
 */

query_door() { return !door_is_open; }

long(str) {
   if(str=="elevator")
     write("The elevator is in the shape of a large rectangle, the\n"+
    "mirrored walls creating the illusion of a larger space than really\n"+
    "exists.\n");
   if(str=="fan" || str=="metal fan")
     write("The steel ventilation fan in the ceiling moves so quickly that\n"+
     "its blades are merely a grey blur beneath the metal guard.  Its \n"+
      "constant hum is just loud enough to be annoying.\n");
   if(str=="loudspeaker")
     write("Muzak crackles with static through the steel mesh of\n"+
     "the loudspeaker inset in the grey ceiling of the elevator.\n");
   if(str=="handrails" || str=="handrail")
     write("Thin steel handrails line the walls to assist unsteady\n"+
     "elevator passengers.\n");
   if(str=="wall" || str=="walls")
     write("The elevator wall is matte white from the floor to the handrail,\n"+
     "and sports a smoky, reflective surface from the handrail to the ceiling.\n");
   if(str=="mirrors" || str=="mirror")
     write("The mirrored walls are smoky grey, darkly reflecting distorted\n"+
     "images of the passengers.\n");
   if(str=="lighting" || str=="track lighting") 
     write("Track lighting runs the circumfrence of the elevator floor\n"+
     "and ceiling, providing soft ambient light for the elevator.\n");
   if(str=="door") 
     write("The heavy oak door to the elevator appears to be thick and secure.\n");
   if(str=="buttons" || str=="button")
     write("The line of buttons is marked with the floor numbers of the\n"+
     "hotel.  To select a floor, simply 'push' or 'press' the floor\n"+ 
     "number. (1-4)\n");
   if(str=="carpet")
     write("The plush grey carpet swallows the feet of elevator passengers\n");
   if(str=="can" || str=="glue" || "aerosol glue")
     write("The empty can of aerosol glue is firmly stuck to the carpet in the\n"+
     "back corner of the elevator.\n");
   if(str) return 0;
  write("The large rectangular elevator seems stuffy despite its relatively\n"+
  "generous size and the constant flow of recycled air from the metal\n"+
  "fan which whirs overhead.  The steady drone of the fan is nearly\n"+
  "drowned out by a particularly energetic muzak version of 'The Girl\n"+
  "From Ipanema' playing at slightly too high a volume over the \n"+
  "elevator's crackly loudspeaker.  Discrete steel handrails line the\n"+
  "perimeter of the elevator at the point where the white matte surface\n"+
  "of the lower wall gives way to the smoky mirrored surface spanning\n"+
  "the area from waist-height to the ceiling.  Muted track lighting \n"+
  "lines the edges of the floor and ceiling, providing ambient light. A\n"+
  "row of buttons, one for each floor, is inset in the wall next to the\n"+
  "door.  An empty can of aerosol glue lies discarded in the back corner\n"+
  "of the elevator, where it had leaked and adhered itself to the fibers\n"+
  "of the plush grey carpet.\n");
   if (door_is_open)
      write("There is an open door to the west.\n");
   if (!door_is_open)
      write("There is a closed door to the west.\n");
}

press(button) {
    string b;
    if (!button)
	return 0;
    if (sscanf(button, "button %s", b) != 1)
	b = button;
    say(this_player()->query_name()+" pushes a button.\n");
    if (door_is_open) {
        write("Nothing happens.\n");
        return 1;
    }
    if (moving_time > 0) {
	write("The elevator is still moving.\n");
	return 1;
    }
    if (b == "1" || b == "one")
	dest = 1;
    if (b == "2" || b == "two")
	dest = 2;
    if (b == "3" || b == "three")
	dest = 3;
    if (b == "4" || b == "four")
       dest = 4;
    if (dest == level) {
	write("You are already at level " + dest + ".\n");
	return 1;
    }
    if(!dest) {
      write("You cannot find that button.\n");
      return 1;
    }
    if (dest > level) {
	moving_time = dest - level;
	write("The elevator jerks upward.\n");
	say("The elevator jerks upward.\n");
    }
    if (level > dest) {
	moving_time = level - dest;
	write("The elevator starts moving downward.\n");
	say("The elevator starts moving downward.\n");
    }
    moving_time += 2;
    set_heart_beat(1);
    return 1;
}

heart_beat() {
    if (time_to_close_door > 0) {
	time_to_close_door -= 1;
	if (time_to_close_door == 0) {
	    say("The door swings shut.\n");
            tell_room(levelrm[level], "The elevator door shuts.\n");
	    door_is_open = 0;
	}
    }
    if (moving_time <= 0)
	return;
    moving_time -= 1;
    if (moving_time > 0) {
	say("The elevator continues...\n");
	return;
    }
    if (moving_time <= 0 && time_to_close_door <= 0)
    set_heart_beat(0);
    say("The elevator slows down and stops\n");
    level = dest;
    if (level == 4)
        call_other(CASINO+"hall4x1", "elevator_arrives",0);
    if (level == 3)
        call_other(CASINO+"hall3x1", "elevator_arrives",0);
    if (level == 2)
	call_other(CASINO+"hall2x1", "elevator_arrives",0);
    if (level == 1)
	call_other(CASINO+"hall1e1","elevator_arrives",0);
}

open_door(str)
{
    if (str != "door")
	return 0;
    if (door_is_open) {
	write("It is already open!\n");
	return 1;
    }
    if (moving_time > 0) {
	write("The door is stuck.\n");
	return 1;
    }
    door_is_open = 1;
    time_to_close_door = 3;
    set_heart_beat(1);
    write("Ok.\n");
    say(call_other(this_player(), "query_name", 0) + " opened the door.\n");
    return 1;
}

close_door(str)
{
    if (str != "door")
	return 0;
    if (!door_is_open) {
	write("It is closed!\n");
	return 1;
    }
    door_is_open = 0;
    time_to_close_door = 0;
    write("Ok.\n");
    say(call_other(this_player(), "query_name", 0) + " closed the door.\n");
    tell_room(levelrm[level], "The elevator door shuts.\n");
    return 1;
}

go_west() {
    if (moving_time > 0) {
	write("You can't go anywhere when the elevator is moving.\n");
	return 1;
    }
    if (!door_is_open) {
	write("The door is closed.\n");
	return 1;
    }
    if (level == 4)
       call_other(this_player(), "move_player","west#"+CASINO+"hall4x1");
    if (level == 3)
       call_other(this_player(), "move_player","west#"+CASINO+"hall3x1");
    if (level == 2)
	call_other(this_player(), "move_player","west#"+CASINO+"hall2x1");
    if (level == 1)
       call_other(this_player(),"move_player","west#"+CASINO+"hall1e1");
    return 1;
}

query_level() { return level; }

/*
 * This routine is called from various rooms that the elevator connects to.
 */
call_elevator(button) {
    if (door_is_open)
	return 0;
    if (moving_time > 0)
	return 0;
    dest = button;
    if (dest == level) {
       tell_room(levelrm[dest], "The button blinks.\n");
       tell_room(levelrm[dest], "The elevator door opens.\n");
       call_other(CASINO+"elevator", "open_door", "door");
	return 0;
    }
    write("A little white lamp beside the button lights up.\n");
    say("A little white lamp beside the button lights up.\n");
    if (dest > level)
	moving_time = dest - level;
    if (level > dest)
	moving_time = level - dest;
    moving_time += 2;
    set_heart_beat(1);
    return 1;
}

id(str) {
    return str=="elevator" || str=="fan" || str=="metal fan" || 
      str=="loudspeaker" || str=="handrails" || str=="handrail" ||
      str=="wall" || str=="walls" || str=="mirrors" || str=="mirror" ||
      str=="lighting" || str=="track lighting" || str=="door" || 
      str=="buttons" || str=="button" || str=="carpet" || str=="can" || 
      str=="glue" || str=="aerosol glue";
}

/*
 * Only list inventory if not looking at anything special.
 */
can_put_and_get()
{
    return 0;
}
/*
 * Called by others to see if the elevator is moving
 */
is_moving() { 
    if (level == dest )
	/* Still */
	return 0;
    if(level > dest)
	/* down */
	return 1;
    /* up */
    return 2;
}

query_drop_castle() {
    return 1;
}
