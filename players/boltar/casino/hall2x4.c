#define ROOMFACTOR 275;
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
    add_action("west"); add_verb("west");
#else
  add_action("west", "west");
#endif
    add_action("north","north");
    add_action("enter","enter");
}

north() {
  call_other(this_player(),"move_player","north#"+CASINO+"hall2x1");
  return 1;
}
west() { 
  call_other(this_player(),"move_player","west#"+CASINO+"hall2x3");
  return 1;
}
enter(str) {
  int rmnum,bill,myroom,indexrm;
  object key,ob;
  string short_str;
  if(!str || sscanf(str,"%d",rmnum) != 1) {
    write("usage: enter <room number>\n");
    return 1;
  }
  indexrm = rmnum - ROOMFACTOR;
  if(indexrm > 25 || indexrm < 1) {
    write("That room is not in this hallway.\n");
    return 1;
  }
  key=present("CasaNirvanaKey", this_player());
  if(!key) key = this_object();
  myroom=key->query_room_num();
  if(myroom != rmnum) {
    if(!loaded_rooms[indexrm]) {
      write("The door is locked.\n");
      return 1;
    }
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
    return "Casa de Nirvana, 2nd floor hallway";
}

long(str) {
  if (str == "door") 
    write("The heavy oak door appears to be thick and secure.\n");
  if (str == "plaque") 
    write("The thin brass plaque dully reflects the ambient light.\n"+
    "It is ornately engraved with the number to the room.\n");
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
  if (str == "lamp") 
    write("The stained-glass panels of the Tiffany lamp scatter muted\n"+
    "multi-colored light across the wall beside the cherry table on\n"+ 
    "which it rests.\n");
  if (str == "Tiffany lamp") 
    write("The stained-glass panels of the Tiffany lamp scatter muted\n"+
    "multi-colored light across the wall beside the cherry table on\n"+
    "which it rests.\n");
  if (str == "room") 
    write("A sturdy oak door seals off each room from the hallway.\n");
  if (str == "table")
    write("The small round cherry table supports only the Tiffany lamp.\n");
  if (str == "carpet")
    write("The plush beige carpet swallows your feet up to the ankles\n"+
    "as you step onto it.\n+");
  if (str == "border")
    write("The paisley border dances high on the wall with broad swirls\n"+
    "of deep rose, brown, and beige.\n");
  if(str) return 0;
  write("The second floor hallway stretches into the distance with\n"+
  "multiple doors to either side accented with brass plaques\n"+
  "identifying each room number. An ornate marble plate on the\n"+ 
  "corner of the wall reads, 'Rooms 276 - 299'.  Muted ambient\n"+
  "light is provided by a series of tasteful Tiffany lamps resting\n"+
  "on small cherry tables spaced evenly along the length of the\n"+
  "hallway.  A hush lies about the hallway, all sound muffled by\n"+
  "the deep beige carpet which compliments, rather than matches,\n"+
  "the warm paisley pattern on the wall border.  To the west is a\n"+
  "similarly decorated hallway, the marble plate on the corner reading,\n"+
  "'Rooms 251 - 275'.  Another hallway lies to the north, its room\n"+
  "numbers obscured from this distance in the dim light.\n");
  if (lamp_is_lit)
    write("The lamp beside the elevator is lit.\n");

}

id(str) {
    return str == "door" || str ==  "plate" || str == "plaque" || 
           str == "marble plate" || str == "lamp" || str == "Tiffany lamp" || 
           str == "room" || str == "table" || str == "carpet" || 
           str == "border" || str == "elevator" || str=="button"; 
}

