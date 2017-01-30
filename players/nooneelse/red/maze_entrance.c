/*
  maze_entrance.c
*/

inherit "room/room";
realm() { return "NT"; }

reset(arg) {
  object doppleganger_obj;
  if (arg) return;

  set_light(0);
  short_desc = "A plain white room";
  no_castle_flag=1;
  long_desc =
    "Your senses reel as you enter this stark white.\n"+
    "Your eyes hurt as they strugle to focus on something.  Anything.\n"+
    "Though you see nothing in the room, you sense danger from an\n"+
    "unknown source.  There is a small tin plaque on one wall.\n";
  items =
    ({
      "plaque", "The plaque reads 'The doppleganger was made harder at the\n"+
                "                   suggestion of Ozymandias'",
    });
  dest_dir =
    ({
      "players/nooneelse/red/maze_1", "north",
      "players/nooneelse/red/maze_x", "east",
      "players/nooneelse/red/maze_x", "south",
      "players/nooneelse/red/maze_x", "west",
      "players/nooneelse/red/study", "down",
    });
  if (!present("doppleganger")) {
    doppleganger_obj=clone_object("players/nooneelse/mon/doppleganger");
    move_object(doppleganger_obj, this_object());
  }
}

init() {
  ::init();

  add_action("enter_maze", "north");
  add_action("enter_maze", "east");
  add_action("enter_maze", "south");
  add_action("enter_maze", "west");
}

enter_maze() {
  if (present("doppleganger", this_object()) &&
      this_player()->query_level() < 21) {
    write(capitalize(this_player()->query_name())+
          " stands in your way.  You cannot proceed.\n");
    say(capitalize(this_player()->query_name())+
        " stands in "+capitalize(this_player()->query_name())+
        "'s way.  "+capitalize(this_player()->query_pronoun())+
        " cannot proceed.\n", this_player());
    return 1;
  }
  if (this_player()->query_level() >= 21)
    write("<<< A player couldn't walk past the doppleganger >>>\n");
  if (query_verb()=="north") {
    move_object(this_player(), "players/nooneelse/red/maze_1");
    if (this_player()->query_brief())
      tell_object(this_player(), environment(this_player())->short()+"\n");
    else
      command("look", this_player());
    return 1;
  }
  else {
    move_object(this_player(), "players/nooneelse/red/maze_x");
    if (this_player()->query_brief())
      tell_object(this_player(), environment(this_player())->short()+"\n");
    else
      command("look", this_player());
    return 1;
  }
}
