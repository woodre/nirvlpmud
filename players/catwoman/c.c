inherit "room/room";
object dog2;

reset(arg)
{
  if (!dog2) {
	dog2 = clone_object("/players/catwoman/monster/dog");
	move_object(dog2, this_object());
	}
  if (arg) return;

  set_light(1);
  short_desc = "---Cobble stone path---";
  no_castle_flag = 0;
                                                         
  long_desc = "A Cobble stone path\n"+"obvious exits are north and east.\n";

}

init ()
   {
    add_action ("north","north");
/*    add_action ("west"); add_verb ("west");*/
    add_action ("east","east");
    return;
  }
north(){
call_other(this_player(), "move_player", "north#players/catwoman/a");
return 1;
}
east(){
call_other(this_player(), "move_player", "east#players/catwoman/d");
return 1;
}


query_light()
{
  return 1;
}

 

