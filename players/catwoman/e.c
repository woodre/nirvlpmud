inherit "room/room";
object dog3;

reset(arg)
{
  if (!dog3) {
	dog3 = clone_object("/players/catwoman/monster/dog");
	move_object(dog3, this_object());
	}
  if (arg) return;

  set_light(1);
  short_desc = "---Cobble stone path---";
  no_castle_flag = 0;
                                                         
  long_desc = "A Cobble stone path\n"+"obvious exits are west and east.\n";

}

init ()
   {
/*    add_action ("north"); add_verb ("north");*/
    add_action ("west","west");
    add_action ("east","east");
    return;
  }
west(){
call_other(this_player(), "move_player", "west#players/catwoman/b");
return 1;
}
east(){
call_other(this_player(), "move_player", "east#players/catwoman/g");
return 1;
}


query_light()
{
  return 1;
}

 

