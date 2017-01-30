inherit "room/room";


reset(arg)
{
  if (arg) return;

  set_light(0);
  short_desc = "---A tunnel---";
  no_castle_flag = 0;
                                                         
  long_desc = "A tunnel\n"+"obvious exit is west.\n";

}

init ()
   {
/*    add_action ("north"); add_verb ("north");
    add_action ("west"); add_verb ("west");*/
    add_action ("west","west");
    return;
  }
west(){
call_other(this_player(), "move_player", "west#players/catwoman/22");
return 1;
}

query_light()
{
  return 0;
}

 

