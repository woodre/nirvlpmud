inherit "room/room";

reset(arg) {
 if(!arg) {

     set_light(1);
      short_desc = "Residence Hall";
      long_desc =
"You pass through probably the most intense security in the nation\n"+
"(ie. the sleeping door guard that is either asleep or reading, oblivious\n"+
"to the world.  You notice a foul odor eminating from the north.\n"+
"Maybe you shoud check it out, or maybe it be best to leave what's there\n"+
"alone.  The choice is yours.\n"+
"GradHall is to the east, Cohean lounge is to the south.\n";
       dest_dir = ( {
                "players/lew/entrance", "west", } );
  return 1;
}
}
init() {
  ::init();
          add_action("north", "north");
          add_action("south", "south");
          add_action("east", "east");
       return 1;}
north() {

   if(!present("idcard", this_player())) {
       tell_object(this_player(), "Guard shouts: You must have your id!\n");
       return 1; }
    move_object(this_player(), "players/lew/cafeteria");
    call_other(this_player(), "look");
    return 1;
}
south() {
    if(!present("idcard", this_player())) {
    tell_object(this_player(), "Guard shouts: You must have your id!\n");
    return 1; }
    move_object(this_player(), "players/lew/lounge");
    call_other(this_player(), "look");
    return 1;
}
east() {
    if(!present("idcard", this_player())) {
    tell_object(this_player(), "Guard shouts: You must have your id!\n");
    return 1; }
    move_object(this_player(), "players/lew/grad/firstfloor");
    call_other(this_player(), "look");
    return 1;
}
