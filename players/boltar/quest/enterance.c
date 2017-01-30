int digcount;
int ring_status;
id(str) { return str == "cave"; }
init() {
      digcount = 0;
       set_light( 1);
      add_action("up","up");
      add_action("south","south");
      add_action("search","search");
      add_action("north","north");
      add_action("look","look");
      add_action("search","examine");
      add_action("look","l");
      add_action("search","exa");
}
 short() { return "cave under the Legion of the dead office."; }
long() {
 write("You are in a large cave under the Big House.  It looks as though no\n");
 write("one has been in here for years. In the wall there is a small nook, and along \n");
 write("both sides of the cave there are holders for torches long since gone.\n");
 write("There is a way back up to the Big House and northward through the cave.\n");
 write("You also see a small passageway to the south.\n");
}
 north() {
  call_other(this_player(), "move_player", "north#players/boltar/quest/quest_cave.c");
  return 1;
}
south() {
   call_other(this_player(), "move_player", "south#players/boltar/quest/add_on.c");
 return 1;
 }
 up() {
     call_other(this_player(), "move_player", "up#players/boltar/sprooms/dead_office.c");
  return 1;
}
search(str) {
   object ring;
     if(!str) {
     long();
     return 1;
     }
   if(str == "nook") {
   if (!ring_status) {
  write("All you find is the remains of someone's hand and alot of dust.\n");
   return 1;
  }
  ring = clone_object("players/boltar/things/quest_ring.c");
  move_object(ring, this_player());
  ring_status = 0;
  write("You found a ring!!!\n");
   write("And it magically takes flight and lands in your hand.\n");
  return 1;
}
 return 1;
}
look(str) {
   if (!str) {
   return 0;
  }
  if (str == "at nook" || str == "in nook"){
   write("You see a small point of light reflect back at you.\n");
   return 1;
  }
return 0;
}
reset() {
 ring_status = 1;
 }
