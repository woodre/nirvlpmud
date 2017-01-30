#define ROOMFACTOR 300;
#define CASINO "players/boltar/casino/"
int lamp_is_lit;
object loaded_rooms;

reset(arg) {
  int i,x;
  if (arg) return;
  set_light(1);
  loaded_rooms = allocate(30);
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("east"); add_verb("east");
#else
  add_action("east", "east");
#endif
    add_action("west","west");
    add_action("south","south");
    add_action("enter","enter");
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

south() {
  call_other(this_player(),"move_player","south#"+CASINO+"hall3x4");
  return 1;
}
west() { 
  call_other(this_player(),"move_player","west#"+CASINO+"hall3x2");
  return 1;
}
enter(str) {
  int rmnum,myroom,indexrm,bill;
  object key,ob;
  string short_str;
  if(!str || sscanf(str,"%d",rmnum) != 1) {
    write("usage: enter <room number>\n");
    return 1;
  }
  indexrm = rmnum - ROOMFACTOR;
  if(indexrm > 25 || indexrm < 0) {
    write("That room is not in this hallway.\n");
    return 1;
  }
  key=present("CasaNirvanaKey", this_player());
  if(!key) key = this_object();
  myroom=key->query_room_num();
  if(myroom != rmnum) {
   if(this_player()->query_real_name() == "boltar" && !loaded_rooms[indexrm]) {
      loaded_rooms[indexrm]=clone_object(CASINO+"room");
      loaded_rooms[indexrm]->set_room_number(rmnum);
    }
    if(!loaded_rooms[indexrm]) {
      write("The door is locked.\n");
      return 1;
    }
   if(this_player()->query_real_name() != "boltar")
    if(loaded_rooms[indexrm]->query_lock()) {
      write("The door is locked.\n");
      return 1;
    }
    write("You open the door and enter room "+rmnum+".\n");
    say(this_player()->query_name()+" enters room "+rmnum+".\n");
    move_object(this_player(),loaded_rooms[indexrm]);
    call_other(loaded_rooms[indexrm], "long", 0);
    ob = loaded_rooms[indexrm];
    ob = first_inventory(ob);
    while(ob) {
      if (ob != this_player()) {
        short_str = call_other(ob, "short");
        if (short_str)
          write(short_str + ".\n");
      }
      ob = next_inventory(ob);
    }
    return 1;
  }
  if(myroom == rmnum) {
    bill=call_other(CASINO+"front_desk", "cost", myroom);
    if(bill) {
      write("You swipe your keycard, the readout says:\n"+
      "BALANCE DUE: "+bill+" coins\n");
      write("The door remains locked.\n");
      write("You must go downstairs and pay your bill first.\n");
      return 1;
    }
    if(!loaded_rooms[indexrm]) {
      loaded_rooms[indexrm]=clone_object(CASINO+"room");
      loaded_rooms[indexrm]->set_room_number(rmnum);
      write("You unlock the door.\n");
    }
    if(loaded_rooms[indexrm]->query_lock()) write("You unlock the door.\n");
    write("You open the door and enter your room.\n");
    say(this_player()->query_name()+" enters room "+rmnum+".\n");
    move_object(this_player(),loaded_rooms[indexrm]);
    call_other(loaded_rooms[indexrm], "long", 0);
    ob = loaded_rooms[indexrm];
    ob = first_inventory(ob);
    while(ob) {
      if (ob != this_player()) {
        short_str = call_other(ob, "short");
        if (short_str)
          write(short_str + ".\n");   
      }
      ob = next_inventory(ob);
    }
    return 1;
  }
}

short() {
    return "Casa de Nirvana, 3rd floor hallway";
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
  if (str ==  "plate" || str == "marble plate")
    write("The small marble plate is engraved with the room numbers that\n"+
    "can be found along this stretch of hallway.\n"+
    "There is a small map posted below it:\n"+
    "          ____________________________\n"+
    "          |         26 to 50    |    |\n"+
    "          |_____________________|    |\n"+
    "          |    |                | 00 |_________\n"+
    "  ________| 51 |                | to |elevator |\n"+
    "  | Stairs  to |                | 25 |_________|\n"+
    "  |_______  75 |                |    |\n"+
    "          |    |________________|____|\n"+
    "          |    |     76 to 99        |\n"+
    "          |____|_____________________|\n");
  if (str == "plaque") 
    write("The thin brass plaque dully reflects the ambient light.\n"+
    "It is ornately engraved with the number to the room.\n");
  if (str == "room") 
    write("A sturdy oak door seals off each room from the hallway.\n");
  if (str == "elevator")
    write("Broad oak doors separate the elevator from the hallway.\n");
  if (str=="button" && !lamp_is_lit)
    write("The discrete elevator button glows dully at waist level beside\n"+
    "the elevator doors.\n");
  if (str=="button" && lamp_is_lit)
    write("The discrete elevator button glows brightly at waist level beside\n"+
    "the elevator doors.\n");
  if (str== "hallway") 
    write("The long, plush hallway stretches to a corner in the distance.\n");
  if (str=="window")
    write("Large picture windows afford a stunning view of the surrounding\n"+
    "area, and fill the corner of the hallway with light from outside.\n");
  if (str=="sculpture")
    write("The heavy plaster scuplture resembles two cherubs frolicking.\n");
  if (str=="pillar")
    write("The cool, smooth marble pillar stands waist-high and is just\n"+
    "large enough to support the sculpture that rests upon it.\n");
  if (str=="lighting" || str=="track lighting") 
    write("Soft track lighting lines the edges of the floor and \n"+
    "ceiling along the length of the hallway, providing unfocused\n"+
    "ambient light.\n");
  if (str=="carpet")
    write("The plush forest green carpet swallows your feet up to\n"+
    "the ankles as you step onto it.\n");

  if(str) return 0;
  write("The third floor hallway is brighter than that of the lower floor,\n"+
  "with large picture windows at either end of the hallway spilling\n"+
  "outside light across the forest green carpet.  Rows of sturdy oak\n"+
  "doors line the hallway on either side, each accented with a brass\n"+
  "plaque identifying its room number. An ornate marble plate on the\n"+ 
  "corner of the wall reads, 'Rooms 300 - 325'.  Soft track lighting\n"+
  "runs the length of the hallway.  Several small sculptures stand\n"+
  "patiently on short marble pillars spaced evenly along the\n"+
  "hallway.  It is silent, save for the soft hum of the furnace \n"+
  "and air conditioning unit.  The walls are a muted beige up to\n"+
  "waist height and a deep forest green from there to the ceiling\n"+
  "with a thin border of cherry wood separating the blocks of color.\n"+
  "To the south is a similarly decorated hallway, the marble plate \n"+
  "on the corner reading, 'Rooms 376 - 399'.  Another hallway lies to\n"+
  "the west, its room numbers obscured from this distance. To the east\n"+
  "are the heavy wooden doors of the elevator flanked by a discrete\n"+
  "button on either side.\n");

  if (lamp_is_lit)
    write("The lamp beside the elevator is lit.\n");

}

id(str) {
    return str == "door" || str ==  "plate" || str == "plaque" || 
           str == "marble plate" || str == "room" || str == "elevator" ||
           str=="button" || str=="button" || str== "hallway" ||
           str=="window" || str=="sculpture" || str=="pillar"||
           str=="lighting" || str=="track lighting" || str=="carpet";
}

east() {
    if (call_other(CASINO+"elevator", "query_door", 0) ||
	call_other(CASINO+"elevator", "query_level", 0) !=3) {
	write("The door is closed.\n");
	return 1;
    }
    call_other(this_player(), "move_player","east#"+CASINO+"elevator");
    return 1;
}

open(str)
{
    if (str != "door")
	return 0;
    if (call_other(CASINO+"elevator", "query_level", 0) !=3) {
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
    if (call_other(CASINO+"elevator", "call_elevator", 3))
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
