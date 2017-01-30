inherit "room/room";


reset(arg)
{
  if (arg) return;

  set_light(1);
  short_desc = "A large cave";
  no_castle_flag = 0;
                                                         
  long_desc = "A large mirror is located to the south.\n"+" exits are north,east and west.\n";
/*  dest_dir =
   ({ "players/catwoman/c1", "north",
      "players/catwoman/6", "east",
      "players/catwoman/2", "west", });*/
}

init ()
   {
    add_action ("touch","feel");
    add_action ("touch","touch");
    add_action ("north","north");
    add_action ("east","east");
    add_action ("west","west");
     return;

  }
north() {
	call_other(this_player(), "move_player", "north#players/catwoman/c1");
	return 1;
}

east() {
	call_other(this_player(), "move_player", "east#players/catwoman/6");
	return 1;
}

west() {
	call_other(this_player(), "move_player", "west#players/catwoman/2");
	return 1;
}

touch(str)               
 {
    if (str != "mirror")
	return 0;
    if (str = "mirror")
    write("The whole room shakes.\n");
    call_other(this_player(), "move_player", "in#players/catwoman/mirror3");
    return 1;
  }

query_light()
{
  return 1;
}

 
