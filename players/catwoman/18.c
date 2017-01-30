inherit "room/room";
object bat3;

reset(arg)
{
  if (!bat3){
	bat3 = clone_object("/players/catwoman/monster/gbat");
	move_object(bat3, this_object());
	}
  if (arg) return;

  set_light(1);
  short_desc = "---A tunnel---";
  no_castle_flag = 0;
                                                         
  long_desc = "A tunnel\n"+"obvious exits are west and south.\n";

}

init ()
   {
/*    add_action ("north"); add_verb ("north");*/
    add_action ("west","west");
    add_action ("south","south");
    return;
  }
west(){
call_other(this_player(), "move_player", "west#players/catwoman/13");
return 1;
}
south(){
call_other(this_player(), "move_player", "south#players/catwoman/19");
return 1;
}


query_light()
{
  return 1;
}

 
