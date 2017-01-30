#define ROOMFACTOR 425;
#define CASINO "players/boltar/casino/"
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
  call_other(this_player(),"move_player","south#"+CASINO+"hall4x3");
  return 1;
}
east() { 
  call_other(this_player(),"move_player","east#"+CASINO+"hall4x1");
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
    return "Casa de Nirvana, 4th floor hallway";
}

long(str) {
  if (str == "door") 
    write("The heavy oak door appears to be thick and secure.\n");
  if (str ==  "plate" || str == "mirrored plate")
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
  if (str== "hallway")
    write("The long, modern hallway stretches to a corner in the distance.\n");
  if (str== "sky light")
    write("Large sky lights span the ceiling.  They afford a stunning\n"+
    "view of the sky above, creating the illusion that the hallway is open\n"+
    "to the elements.\n");
  if (str=="mirror")
    write("The chrome-framed mirror reflects a stretch ofhallway in the\n"+
    "background behind your image.\n");
  if (str=="mirrors")
    write("Chrome-framed mirrors reflect the ambient light, creating the\n"+
    "illusion of an endless hallway.\n");
  if (str=="lamp") 
    write("The petite lamp wears a white shade and is attached to the wall\n"+
    "by a lovely curved chrome fixture.\n");
  if (str=="lamps") 
    write("Small lamps in chrome and white hang discretely from the walls\n"+
    "on either side of the hallway.\n");
  if (str=="flowers" || str=="flower arrangements")
    write("An impressive variety of flowers in all imaginable shades of\n"+
  "blues, reds, yellows, and purples crowd into the top of each white\n"+
  "ceramic urn, pressing tight against the tendrils of ivy, then flow\n"+
  "down over the sides nearly to the floor.\n");
  if (str=="urn")
    write("Knee-high white ceramic urns with textured cherubs on each side\n"+
  "are nearly hidden by the flower arrangements that fill them.\n");
  if (str=="track lighting" || str=="lighthing")
    write("Soft track lighting lines the edges of the floor along\n"+
    "the length of the hallway.\n");
  if (str=="carpet")
    write("The plush white carpet swallows your feet up to\n"+
    "the ankles as you step onto it.\n");

  if(str) return 0;
  write("The sky hangs low over huge sky lights atop the fourth floor hallway.\n"+
  "The walls are a soft white, accented by long, ornately framed mirrors\n"+
  "which create the illusion of a still larger space.  Rows of sturdy oak\n"+
  "doors line the hallway on either side, each accented with a brass\n"+
  "plaque identifying its room number. An ornate mirrored plate on the\n"+ 
  "corner of the wall reads, 'Rooms 426 - 450'.  Soft track lighting\n"+
  "runs the length of the hallway along the edge of the white carpet,\n"+
  "and modern lamps hang suspended from various points along the wall.\n"+
  "The sweet, heady scent of fresh flowers wafts through the air from\n"+
  "the enormous fresh flower arrangements that spill over the edges of\n"+
  "oversized ceramic floor urns, creating a riot of color against the \n"+
  "otherwise austere decor. It is silent, save for the hum of the furnace\n"+
  "and air conditioning unit.  To the south is a similarly decorated \n"+
  "hallway, the mirrored plate on the corner reading, 'Rooms 451 - 475'.\n"+
  "Another hallway lies to the east, its room numbers obscured from this\n"+
  "distance. \n");
}


id(str) {
    return str == "door" || str ==  "plate" || str == "plaque" || 
           str == "marble plate" || str == "room" ||
           str=="sky light" || str== "hallway" ||
           str=="mirrors" || str == "lamp" || str == "lamps" ||
           str=="flower arrangements" || 
           str=="mirror" || str=="flowers" || str=="urn" ||
           str=="lighting" || str=="track lighting" || str=="carpet";
}
