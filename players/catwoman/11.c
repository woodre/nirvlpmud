inherit "room/room";


reset(arg)
{

  if (arg) return;

  set_light(1);
  short_desc = "---A tunnel---";
  no_castle_flag = 0;
                                                         
  long_desc = "A tunnel\n"+"obvious exits are north and east.\n";

}

init ()
   {
    add_action ("north","north");
/*    add_action ("west"); add_verb ("west");*/
    add_action ("east","east");
    return;
  }
north(){
call_other(this_player(), "move_player", "north#players/catwoman/10");
return 1;
}
east(){
call_other(this_player(), "move_player", "east#players/catwoman/16");
return 1;
}


query_light()
{
  return 1;
}

 

