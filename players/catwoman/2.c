inherit "room/room";


reset(arg)
{
  if (arg) return;

  set_light(1);
  short_desc = "---A back room---";
  no_castle_flag = 0;
                                                         
  long_desc = "A back room\n"+"there are some stones splatered with blood here.\n"+"obvious exits are west and east.\n";

}

init ()
   {
/*    add_action ("north"); add_verb ("north");*/
    add_action ("west","west");
    add_action ("east","east");
    return;
  }
west(){
call_other(this_player(), "move_player", "west#players/catwoman/1");
return 1;
}
east(){
call_other(this_player(), "move_player", "east#players/catwoman/mirror1");
return 1;
}


query_light()
{
  return 1;
}

 

