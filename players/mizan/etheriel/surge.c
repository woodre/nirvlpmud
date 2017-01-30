int done_tl;
id(str) { return str == "surge"; }

short() { return "A current surge"; }

long() {
  write("It is transparent.\n");
}

init() {
  if(!done_tl) call_out("storm_surge", random(5));
  done_tl=1;
}

storm_surge() {
  tell_room(environment(this_object()),
   "\nYou tense up as your stomach gets a low, grumbly feeling...\n\n");
  call_out("real_surge", 5);
  return 1;
}

real_surge(str) {
  object room;
  object ob;
  int a;
  room=environment(this_object());
  tell_room(room, "A powerful current surge suddenly smashes into you!\n");
  ob=first_inventory(room);
  while(ob) {
    object oc;
    oc=ob;
    ob=next_inventory(ob);
  if(oc != this_object()) {
    if(!oc->query_permanency() && 1== random(4)) {
      string mover;
      mover=call_other("players/mizan/closed/RandomRoomDM.c", "one_random");
      if(oc->short()) {
        tell_room(room,
        (oc->short()) + " is swept away by the surge!\n");
  tell_object(oc, "You are caught in a powerful current surge! It sweeps you elsewhere.\n");
      }
      move_object(ob, "/players/mizan/etheriel/ROOMS/" + mover);
      if(oc->short()) {
        tell_room(room,
        (oc->short()) + " drifts into view, bongled by a current surge.\n");
      }
    }
  }
  }
  if(1 == random(2)) {
    int i;
    i=random(5);
    while(i < 6) {
      object thingo;
      string mover2;
      mover2=call_other("players/mizan/closed/RandomRoomDM.c", "one_random");
      thingo=clone_object("players/mizan/etheriel/surge.c");
      move_object(thingo, "/players/mizan/etheriel/ROOMS/" + mover2);
    }
  }
  destruct(this_object());
  return 1;
}

