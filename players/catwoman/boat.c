

#include "std.h"
/*
 * This is an elevator.
 * floor 2: church
 */

#define STILL0
#define DOWN1
#define UP2

int level;
int gate_is_open;
int time_to_close_gate;
int dest;/* Where we are going. */
int moving_time;/* How long we are going to move. */
int delay_to_reset;/* Move back to origin automatically after a delay. */
 

init() {
    add_action("press","pull");
    add_action("press","push");
    add_action("open_gate","open");
    add_action("close_gate","close");
    add_action("go_east","west");
}

short() {
    return "A ship";
}

reset(arg) {
    gate_is_open = 0;
    if (arg)
 
return;
    set_light(1);
    level = 2;
    dest = 2;
    moving_time = 0;
}

/*
 * Return true if closed gate.
 */

query_gate() { return !gate_is_open; }

long() {
    write("You are in the boat. On the floor are three levers,\n");
    write("numbered 1 to 3.\n");
    if (gate_is_open)
write("There is an open gate to the west.\n");
    if (!gate_is_open)
write("There is a closed gate to the west.\n");
}

press(lever) {
    string b;
    if (!lever)
return 0;
    if (gate_is_open) {
write("Nothing happens.\n");
return 1;
    }
    if (sscanf(lever, "lever %s", b) != 1)
b = lever;
 
    if (moving_time > 0) {
write("The ship is still moving.\n");
return 1;
    }
    if (b == "1" || b == "one")
dest = 1;
    if (b == "2" || b == "two")
dest = 2;
    if (b == "3" || b == "three")
dest = 3;
    if (dest == level) {
write("You are alread at " + dest + ".\n");
return 1;
    }
    if (dest > level) {
moving_time = dest - level;
 
write("The ship sets sail.\n");
say("The ship sets sail.\n");
    }
    if (level > dest) {
moving_time = level - dest;
write("The ship sets sail.\n");
say("The ship sets sail.\n");
    }
    if (dest == 1 || level == 1)
moving_time += 10;
    moving_time += 1;
    set_heart_beat(1);
    return 1;
}

heart_beat() {
 
    if (time_to_close_gate > 0) {
time_to_close_gate -= 1;
if (time_to_close_gate == 0) {
    say("The gate swings shut.\n");
    gate_is_open = 0;
}
    }
    if (moving_time <= 0)
return;
    moving_time -= 1;
    if (moving_time > 0) {
say("Sailing sailing...\n");
return;
    }
    say("The ship slows down and stops\n");
    set_heart_beat(0);
 
    level = dest;
    if (level == 2)
call_other("players/catwoman/dock2", "elevator_arrives", 0);
    if (level == 1)
call_other("players/catwoman/dock1", "elevator_arrives",0);
}

open_gate(str)
{
    if (str != "gate")
return 0;
    if (gate_is_open) {
write("It is already open!\n");
return 1;
    }
    if (moving_time > 0) {
 
write("The gate is stuck.\n");
return 1;
    }
    gate_is_open = 1;
    time_to_close_gate = 3;
    write("Ok.\n");
    say(call_other(this_player(), "query_name", 0) + " opened the gate.\n");
    return 1;
}

close_gate(str)
{
    if (str != "gate")
return 0;
    if (!gate_is_open) {
write("It is closed!\n");
 
return 1;
    }
    gate_is_open = 0;
    time_to_close_gate = 0;
    write("Ok.\n");
    say(call_other(this_player(), "query_name", 0) + " closed the gate.\n");
    return 1;
}

go_east() {
    if (moving_time > 0) {
write("You can't go anywhere when the ship is moving.\n");
return 1;
    }
    if (!gate_is_open) {
write("The gate is closed.\n");
 
return 1;
    }
    if (level == 2)
call_other(this_player(), "move_player", "west#players/catwoman/dock2");
    if (level == 1)
call_other(this_player(), "move_player", "west#players/catwoman/dock1");
    if (level == 3)
call_other(this_player(), "move_player", "west#players/catwoman/dock3");
    return 1;
}

query_level() { return level; }

/*
 * This routine is called from various rooms that the elevator connects to.
 */
 
call_elevator(lever) {
    if (gate_is_open)
return 0;
    if (moving_time > 0)
return 0;
    dest = lever;
    if (dest == level)
return 0;
    write("A little white lamp beside the lever lights up.\n");
    say("A little white lamp beside the lever lights up.\n");
    if (dest > level)
moving_time = dest - level;
    if (level > dest)
moving_time = level - dest;
    if (dest == 1 || level == 1)
moving_time += 10;
 
    moving_time += 1;
    set_heart_beat(1);
    return 1;
}

id(str) {
    return str == "gate" || str == "lever" || str == "levers";
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
 
