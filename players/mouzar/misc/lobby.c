#define ME this_player()
#define rn this_player()->query_real_name()
#define env(str) environment(str)
id(str) { return str=="lobby"||str=="room"; }
short() { return "Lobby [n,s]"; }
long() { write("This is a comfortable room.  The huge oak trees outside keeps this place\n"+
               "cool and relaxing.  There is a desk on the west wall where a clerk stands\n"+
               "There is a picture of Mouzar on the wall over the desk and another picture\n"+
               "of someone unknown but not forgotten.  There is a door leading south where\n"+
               "the rooms are located and another door going north that leads out.  You may\n"+
               "check in or out.  A room costs 500 gold coins."+
		"\n     The only obvious exits are: south, north.\n"); }
reset(arg) { 
  set_light(1); 
}
init() {  
  add_action("south","south");
  add_action("north","north");
  add_action("check","check");
}
south() {
  ME->move_player("south#players/mouzar/inn/hall");
  return 1;
}
north() {
  ME->move_player("north#room/yard3");
  return 1;
}
check(str) {
  object new;
  object room;
  object new_room;
  if(!str) { 
    write("Clerk says:  Do you want to check in or out?\n"); 
    return 1; 
  }
  if(str != "out" && str != "in") { 
    write("Clerk says:  Huh?\n"); 
    return 1; 
  }
  if(str == "in") {
    if(ME->query_gold() < 500) {
      write("Clerk says:  You don't have that much gold.\n");
      return 1;
    }
    room = first_inventory("/players/mouzar/inn/hall");
    if(!room) {
      ME->add_gold(-500);
      new = clone_object("players/mouzar/inn/room");
      new->set_owner(rn);
      new->set_locked("no");
      move_object(new, "players/mouzar/inn/hall");
      write("Clerk says:  Your room is right down the hall to the south.\n");
      return 1; 
    }
    while(room) {
      if(room->query_owner() != rn) {
        new_room = next_inventory(room);
         if(!new_room) { 
          ME->add_gold(-500);
          new = clone_object("players/mouzar/inn/room");
          new->set_owner(rn);
          new->set_locked("no");
          move_object(new, "players/mouzar/inn/hall");
          write("Clerk says:  Your room is right down the hall to the south.\n");
          return 1;
        }
        room = new_room;
      }
      if(room->query_owner() == rn) {
        write("Clerk says:  You already have a room.\n");
        return 1; 
      }
    }   
  }  
  if(str == "out") {
    room = first_inventory("/players/mouzar/inn/hall");
    if(!room) {
      write("Clerk says:  You did not have a room here.\n");
      return 1; 
    }
    while(room) {
      if(room->query_owner() != rn) {
        room = next_inventory(room);
         if(!room) { 
          write("Clerk says:  You did not have a room here.\n");
          return 1;
        }
      }
      if(room->query_owner() == rn) {
        destruct(room);
        write("Clerk says:  Thanks for staying at Mouzar's Inn.  Hope you come back.\n");
        return 1; 
      }
    }   
  }  
  return 1;      
}
  
