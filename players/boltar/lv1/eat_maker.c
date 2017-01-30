#ifndef __LDMUD__ /* Rumplemintz - original code */
init() {
    add_action("make_em"); add_verb("make");
}
make_em() {
   object log,thing;
   int i;
     call_other("room/slope", "short",0);
      call_other("room/yard","short",0);
      call_other("room/forest2","short",0);
     call_other("room/plane9", "short",0);
     call_other("room/fortress", "short",0);
     call_other("room/well", "short",0);
     call_other("room/alley", "short",0);
     call_other("room/plane3", "short",0);
while( i < 2) {
  thing = clone_object("players/boltar/lv1/eat.c");
  log = clone_object("players/boltar/closed/guild/log.c");
    if(i==1) move_object(log, "room/yard");
    if(i==2) move_object(log, "room/forest2");
    if(i != 1 && i !=2) destruct(log);
   if (i == 1)
   move_object(thing, "room/slope");
   if (i == 2)
   move_object(thing, "room/plane3");
   if (i == 3)
   move_object(thing, "room/alley");
   if (i == 4)
   move_object(thing, "room/well");
   if (i == 5)
   move_object(thing, "room/fortress");
   if (i == 6)
   move_object(thing, "room/plane9");
   i+=1;
  }
  if (find_player("boltar"))
    tell_object(find_player("boltar"), "All creatures have been made.\n");
  return 1;
}
short(){return "A creature maker";}
get(){return 1;
    }
reset(arg) {
   make_em();
 return 1;
}
#else /* New code for LD */
string short() { return "A creature maker"; }
status get() { return 1; }
status make_em() {
  object log,thing;
  int i;
  
  load_object("room/slope");
  load_object("room/yard");
  load_object("room/forest2");
  load_object("room/plane9");
  load_object("room/fortress");
  load_object("room/well");
  load_object("room/alley");
  load_object("room/plane3");
  
  while( i < 2) {
    thing = clone_object("players/boltar/lv1/eat.c");
    log = clone_object("players/boltar/closed/guild/log.c");
    switch (i) {
    case 1:
      move_object(log, "room/yard");
      move_object(thing, "room/slope");
      break;
    case 2:
      move_object(log, "room/forest2");
      move_object(thing, "room/plane3");
      break;
    case 3:
      move_object(thing, "room/alley");
      destruct(log);
      break;
    case 4:
      move_object(thing, "room/well");
      destruct(log);
      break;
    case 5:
      move_object(thing, "room/fortress");
      destruct(log);
      break;
    default:
      move_object(thing, "room/plane9");
      destruct(log);
      break;  
    }
    i += 1;
  }
  if (find_player("boltar"))
    tell_object(find_player("boltar"), "All creatures have been made.\n");
  return 1;
}
#endif
