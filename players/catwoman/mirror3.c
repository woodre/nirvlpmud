
inherit "room/room";


reset(arg)
{
  if (arg) return;

  set_light(1);
  short_desc = "A large cave";
  no_castle_flag = 0;
                                                         
  long_desc = "A large mirror is located to the south.\n"+"exits are north, east and west.\n";
/*  dest_dir =
   ({ "players/catwoman/c2", "north",
      "players/catwoman/7", "east",
      "players/catwoman/2", "west", });
*/
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
touch(str)               
 {
    if (str != "mirror")
	return 1;
    if (str = "mirror")
    write("The whole room shakes.\n");
    call_other(this_player(), "move_player", "in#players/catwoman/mirror1");
    return 1;
  }

north() {
/* This is the most moronic and frustrating thing I've ever seen. -Feldegast 1-25-00
	if (this_player()->query_level() != 7 ){
	write("You're the wrong level!\n");
   return 1; }
*/
  if(this_player()->query_level() > 5) {
    write("You have a sudden and inexplicable intuition that only low-level\n"+
      "players can go north from here.\n");
    return 1;
  }
if(this_player()->query_alignment() < 1000) {
  write("You are not pure enough at heart to venture north.\n");
  return 1; }
	call_other(this_player(), "move_player", "north#players/catwoman/c2");
  return 1;
	}
west() {
	call_other(this_player(), "move_player", "west#players/catwoman/2");
	return 1;
	}
east() {
	call_other(this_player(), "move_player", "east#players/catwoman/7");
	return 1;
	}

query_light()
{
  return 1;
}


