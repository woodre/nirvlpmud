#define ROOMFACTOR 1;
#define CASINO "players/boltar/motel/"
int lamp_is_lit;
object loaded_rooms;

reset(arg) {
  int i,x;
  if (arg) return;
  set_light(1);
  loaded_rooms = allocate(30);
}

init() {
    add_action("west","west");
    add_action("enter","enter");
    if(this_player() && this_player()->query_level() > 1000) 
    add_action("list","list");
}

west() { 
  call_other(this_player(),"move_player","west#"+CASINO+"front_desk");
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
  key=present("MotelKey", this_player());
  if(!key) key = this_object();
  myroom=key->query_room_num();
  if(!myroom) myroom=3145926;
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
    return "Motel Hallway";
}

long(str) {
  if (str == "plate")
    write("An old, cheap, plastic plate engraved with the number to the room.\n");
  if (str == "room") 
    write("A worn wood door seals off each room from the hallway.\n");
  if (str == "floor") 
    write("The floor is worn and dirty.\n");
  if (str == "window") 
    write("The window is dirty and looks out on a brick wall of a neighboring building.\n");
  if (str == "wall" || str=="walls"|| str == "ceiling") 
    write("The walls and ceiling are in desparate need of painting.\n");
  if (str == "trash") 
    write("A bunch of old beer bottles and paper.\n");
  if(str) return 0;
  write("This dimly lit hallway has room doors to either side for each\n"+
        "of the motel's rooms. Each door has a plate on it with the room\n"+
        "number. At the end of the hallway is a window facing a brick \n"+
        "wall. The wood floor of the hallway is worn and there is trash\n"+
        "laying about. The walls and ceiling have peeling paint. You may\n"+
        "enter your room from here, but don't want to touch more than \n"+
        "needed.\n");
  return 1;
}       

id(str) {
    return str == "door" || str ==  "plate" || str == "floor" || 
           str == "window" || str == "ceiling" || str == "wall" || 
           str == "room" || str == "walls";
}

list() {
  int i;
  i = ROOMFACTOR;
  while (i <= 25) {
  write(i+"\t"+loaded_rooms[i]+"\n");
  i += 1;
  }
  return 1;
}
