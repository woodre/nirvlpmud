inherit "room/room";

reset(arg)
{
  if (arg) return;

  set_light(1);
  short_desc = "---Cobble stone path---";
  no_castle_flag = 0;
                                                         
  long_desc = "A cobble stone path\n"+"To the east is the gardener's shack.\n"+"west takes you back to the front of the mansion.\n"+"obvious exits are north, east, west and south.\n";

}

#if 0 /* Rumplemintz */
init ()
   {
    add_action ("north"); add_verb ("north");
    add_action ("west"); add_verb ("west");
    add_action ("south"); add_verb ("south");
    add_action ("east"); add_verb ("east");

    return;
  }
#else
init() {
  add_action("north", "north");
  add_action("west", "west");
  add_action("south", "south");
  add_action("east", "east");
}
#endif
north(){
call_other(this_player(), "move_player", "north#players/catwoman/b");
return 1;
}
west(){
call_other(this_player(), "move_player", "west#players/catwoman/road2");
return 1;
}
south(){
call_other(this_player(), "move_player", "south#players/catwoman/c");
return 1;
}
east(){
write("a tree blocks your way *rumor has it you can get there from metropolis.\n");
return 1;
}

query_light()
{
  return 1;
}

