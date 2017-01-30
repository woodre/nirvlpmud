inherit "room/room";


reset(arg)
{
  if (arg) return;

  set_light(1);
  short_desc = "---A tunnel---";
  no_castle_flag = 0;
                                                         
  long_desc = "A tunnel\n"+"obvious exits are west and east.\n";

}

init ()
   {
/*    add_action ("north"); add_verb ("north");*/
    add_action ("west","west");
    add_action ("east","east");
    return;
  }
west(){
call_other(this_player(), "move_player", "west#players/catwoman/mirror3");
return 1;
}
east(){
call_other(this_player(), "move_player", "east#players/catwoman/8");
return 1;
}


query_light()
{
  return 1;
}

 

