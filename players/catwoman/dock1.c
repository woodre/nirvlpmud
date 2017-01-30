int lamp_is_lit;

reset(arg)
{
    if (arg)
return;
    set_light(1);
}

init()
{
    add_action("west","west");
    add_action("east","east");
    add_action("open","open");
    add_action("push","push");
    add_action("push","pull");
    add_action("close","close");
 
}

short() {
    return "The boardwalk";
}

long(str)
{
    if (str == "gate") {
if (!call_other("players/catwoman/boat", "query_gate", 0) &&
    call_other("players/catwoman/boat", "query_level", 0))
    write("The gate is open.\n");
else
    write("The gate is closed.\n");
return;
    }
    write("This is the boardwalk.\n");
    write("There is a lever on the floor here.\n");
    write("Obvious exits are east, west.\n");
    if (lamp_is_lit)
        write("The lamp beside the lever is lit.\n");

}

id(str) {
    return str == "gate";
}
west() {
	call_other(this_player(), "move_player","west#players/catwoman/city/43");
	return 1;
}
east() {
    if (call_other("players/catwoman/boat", "query_gate", 0) ||
call_other("players/catwoman/boat", "query_level", 0) != 1) {
write("The gate is closed.\n");
return 1;
    }
 
    call_other(this_player(), "move_player", "east#players/catwoman/boat");
    return 1;
}

open(str)
{
    if (str != "gate")
return 0;
    if (call_other("players/catwoman/boat", "query_level", 0) != 1) {
write("You can't when the boat isn't here.\n");
return 1;
    }
    call_other("players/catwoman/boat", "open_gate", "gate");
    return 1;
}


close(str)
{
    if (str != "gate")
return 0;
    call_other("players/catwoman/boat", "close_gate", "gate");
    return 1;
}

push(str)
{
    if (str && str != "lever")
return 0;
    if (call_other("players/catwoman/boat", "call_elevator", 1))
lamp_is_lit = 1;
    return 1;
}
 

elevator_arrives()
{
    say("The lamp beside the lever goes out.\n");
    lamp_is_lit = 0;
}

prevent_look_at_inv(str)
{
    return str != 0;
}

