inherit "room/room";

object drunk;
reset(arg) {
    if (arg) return;

     drunk();
    set_light(1);
    short_desc = "Main Street";
    no_castle_flag = 0;
    long_desc = 
        "This is the Main Street of ReesePort.  You are standing on the corner of the\n"
        + "town's general store.\n";
    dest_dir = 
        ({
         "players/grimm/town/mainstreet_2", "east",
         "players/grimm/town/mainstreet_6", "south",
        });
}

drunk() {
  drunk = clone_object("players/grimm/monster/drunk");
  if (!present("drunk")) {
    move_object(drunk,this_object());
  }
 return 1;
}
