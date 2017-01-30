inherit "room/room";

reset(arg)
{
/*
	if (!gardener) {
	gardener = clone_object("/players/catwoman/monster/gardener");
	move_object(gardener, this_object());
	}
*/
  if (arg) return;

  set_light(1);
  short_desc = "Cross Roads";
  no_castle_flag = 0;
                                                         
long_desc =
  "You are at the edge of the island.  You cannot\n"+
  "see because of the mist.\n"+
  "Obvious exits:  north, east\n";

}

init ()
   {
     add_action("north"); add_verb("north");
    add_action ("west"); add_verb ("west");
    add_action ("east"); add_verb ("east");
    return;
  }
east(){
call_other(this_player(),"move_player","west#players/catwoman/dock2");
return 1;
}
north(){
call_other(this_player(), "move_player", "east#players/catwoman/1");
return 1;
}


query_light()
{
  return 1;
}

 

