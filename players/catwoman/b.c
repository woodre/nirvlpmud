inherit "room/room";
object dog1;

reset(arg)
{
  if (!dog1) {
	dog1 = clone_object("/players/catwoman/monster/dog");
	move_object(dog1, this_object());
	}
  if (arg) return;

  set_light(1);
  short_desc = "---Cobble stone path---";
  no_castle_flag = 0;
                                                         
  long_desc = "A Cobble stone path\nTo the north is a time portal\n"+"obvious exits are east and south.\n";

}

init ()
   {
    add_action ("north","north");
    add_action ("east","east");
    add_action ("south","south");
    return;
  }
east(){
call_other(this_player(), "move_player", "east#players/catwoman/e");
return 1;
}
south(){
call_other(this_player(), "move_player", "south#players/catwoman/a");
return 1;
}
north(){
call_other(this_player(), "move_player", "north#players/catwoman/city/2");
return 1;
}

query_light()
{
  return 1;
}

 
