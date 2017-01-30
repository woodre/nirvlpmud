#define ROOMFACTOR 325;
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
    add_action("south","south");
    add_action("enter","enter");
}

south() {
  call_other(this_player(),"move_player","south#"+CASINO+"hall3x3");
  return 1;
}
east() { 
  call_other(this_player(),"move_player","east#"+CASINO+"hall3x1");
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
    return "Casa de Nirvana, 3rd floor hallway";
}

long(str) {
  if (str == "door") 
    write("The heavy oak door appears to be thick and secure.\n");
  if (str ==  "plate" || str == "marble plate")
    write("The small marble plate is engraved with the room numbers\n"+
    "that can be found along this stretch of hallway.\n"+
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
  "corner of the wall reads, 'Rooms 326 - 350'.  Soft track lighting\n"+
  "runs the length of the hallway.  Several small sculptures stand\n"+
  "patiently on short marble pillars spaced evenly along the\n"+
  "hallway.  It is silent, save for the soft hum of the furnace \n"+
  "and air conditioning unit.  The walls are a muted beige up to\n"+
  "waist height and a deep forest green from there to the ceiling\n"+
  "with a thin border of cherry wood separating the blocks of color.\n"+
  "To the south is a similarly decorated hallway, the marble plate \n"+
  "on the corner reading,'Rooms 351 - 375'.  Another hallway lies to\n"+
  "the east, its room numbers obscured from this distance. \n");
}

id(str) {
    return str == "door" || str ==  "plate" || str == "plaque" || 
           str == "marble plate" || str == "room" ||
           str== "hallway" ||
           str=="window" || str=="sculpture" || str=="pillar"||
           str=="lighting" || str=="track lighting" || str=="carpet";
}
