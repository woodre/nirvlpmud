inherit "room/room";
int i;

object book;
init() {
  add_action("exa","examine",3);
  add_action("search","search");
  ::init();
}
reset(arg) {
  i=1;
    if (arg) return;

    set_light(1);
    short_desc = "Small Alcove";
    no_castle_flag = 0;
    long_desc = 
"After flying through the air you realize that you are in a small alcove\n"+
"far above ReesePort.  The area has just enough room for you to squat down\n"+
"and peer over the edge.  From here you can see ReesePort, the castle of\n"+
"ReesePort, the main town out in the distance, and a vast body of water\n"+
"leading southeast of where you picture the sage's house to be.\n"+
"You notice something sticking out from behind a rock in the corner.\n"+
"The only real exit from here is down, though you may have several ways\n"+
"of achieving it.\n";
    dest_dir =
        ({
         "players/grimm/rooms/enter1", "jump",
         "players/grimm/rooms/enter1", "dive",
         "players/grimm/rooms/enter1", "down",
         "players/grimm/rooms/enter1", "parachute",
         "players/grimm/rooms/enter1", "geronimo",
          "players/grimm/rooms/enter1", "leap",
         "players/grimm/rooms/enter1", "bunji",
        });
}

query_light() {
    return 1;
}

search() {
if(i==1) {
  write("You scrounge around and discover some books hidden behind some rocks.\n");
  book = clone_object("players/grimm/closed/obj/cal_hob_books");
  move_object(book, this_player());
  i--;
} else {
  write("You scrounge around and notice that the books have already been found.\n(Maybe you could try again in a bit (hint hint))\n");
}
  return 1;
}

exa(str) {
if(str=="rocks"||str=="rock") {
  search();
  return 1;
}
return;
}

realm() { return "NT"; }
