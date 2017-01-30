#define CASINO "players/boltar/casino/"
int lamp_is_lit;

reset(arg) {
  if (arg) return;
  if(!present("playbill")) 
   move_object(clone_object("/players/aingeal/casino/playbill"),this_object());
  set_light(1);
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("east"); add_verb("east");
#else
  add_action("east", "east");
#endif
    add_action("west","west");
    add_action("northeast","northeast");
    add_action("north","north");
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("open"); add_verb("open");
    add_action("push"); add_verb("push");
    add_action("push"); add_verb("press");
    add_action("close"); add_verb("close");
#else
  add_action("open", "open");
  add_action("push", "push");
  add_action("push", "press");
  add_action("close", "close");
#endif
}

east() {
  call_other(this_player(),"move_player","east#"+CASINO+"restaurant");
  return 1;
}
west() { 
  call_other(this_player(),"move_player","west#"+CASINO+"front_desk");
  return 1;
}
north() {

call_other(this_player(),"move_player","north#players/aingeal/casino/rooms/theater.c");
 return 1;
}

short() {
    return "Casa de Nirvana, first floor lobby";
}

long(str) {
  if (str == "door") { 
    if (!call_other(CASINO+"elevator", "query_door", 0) &&
      call_other(CASINO+"elevator", "query_level", 0))
      write("The elevator door is open.\n");
    else
      write("The elevator door is closed.\n");
    return;
  }
  if (str == "lamp") 
    write("The stained-glass panels of the Tiffany lamp scatter muted\n"+
    "multi-colored light across the wall beside the cherry table on\n"+ 
    "which it rests.\n");
  if (str == "Tiffany lamp") 
    write("The stained-glass panels of the Tiffany lamp scatter muted\n"+
    "multi-colored light across the wall beside the cherry table on\n"+
    "which it rests.\n");
  if (str == "table")
    write("The small round cherry table supports only the Tiffany lamp.\n");
  if (str == "carpet")
    write("The plush beige carpet swallows your feet up to the ankles\n"+
    "as you step onto it.\n");
  if (str == "elevator")
    write("Broad oak doors separate the elevator from the hallway.\n");
  if (str=="button" && !lamp_is_lit)
    write("The discrete elevator button glows dully at waist level beside\n"+
    "the elevator doors.\n");
  if (str== "panel") 
    write("The tasteful gold panel posted above the door directs patrons\n"+
          "to what lies in the room beyond.\n");
  if (str=="button" && lamp_is_lit)
    write("The discrete elevator button glows brightly at waist level beside\n"+
    "the elevator doors.\n");
  if(str) return 0;
  write("The lobby continues over to the elevator in much the same\n"+
  "appearance. There is a series of tasteful Tiffany lamps resting\n"+
  "on small cherry tables spaced evenly around this portion of the\n"+
  "lobby. A panel above the door to the east reads, 'Restaurant'. An\n"+
  "eye-catching playbill is posted beside the north door showcasing the\n"+
  "nightly live entertainment in the Theater. To the northeast\n"+
  "are the heavy wooden doors of the elevator flanked by a discrete\n"+
  "button on either side.\n");
  if (lamp_is_lit)
    write("The lamp beside the elevator is lit.\n");

}

id(str) {
    return str == "door" || str ==  "plate" || str == "plaque" || 
           str == "marble plate" || str == "lamp" || str == "Tiffany lamp" || 
           str == "room" || str == "table" || str == "carpet" || 
           str == "border" || str == "elevator" || str=="button"; 
}

northeast() {
    if (call_other(CASINO+"elevator", "query_door", 0) ||
	call_other(CASINO+"elevator", "query_level", 0) !=1) {
	write("The door is closed.\n");
	return 1;
    }
    call_other(this_player(),"move_player","northeast#"+CASINO+"elevator");
    return 1;
}

open(str)
{
    if (str != "door")
	return 0;
    if (call_other(CASINO+"elevator", "query_level", 0) !=1) {
	write("You can't when the elevator isn't here.\n");
	return 1;
    }
    call_other(CASINO+"elevator", "open_door", "door");
    return 1;
}

close(str)
{
    if (str != "door")
	return 0;
    call_other(CASINO+"elevator", "close_door", "door");
    return 1;
}

push(str)
{
    if (str && str != "button")
	return 0;
    say(this_player()->query_name()+" pushes a button.\n");
    if (call_other(CASINO+"elevator", "call_elevator", 1))
	lamp_is_lit = 1;
    return 1;
}

elevator_arrives()
{
    say("The lamp on the button beside the elevator goes out.\n");
    lamp_is_lit = 0;
}

prevent_look_at_inv(str)
{
    return str != 0;
}
