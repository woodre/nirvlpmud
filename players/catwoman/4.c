inherit "room/room";


reset(arg)
{
  if (arg) return;

  set_light(1);
  short_desc = "---A closet---";
  no_castle_flag = 0;
                                                         
  long_desc = "A closet\n"+"This is where the gardener keeps his stone carving tools.\n"+"obvious exit is south.\n";

}

init ()
   {
/*    add_action ("north"); add_verb ("north");
    add_action ("west"); add_verb ("west");*/
    add_action ("south","south");
    return;
  }
south(){
call_other(this_player(), "move_player", "south#players/catwoman/mirror1");
return 1;
}

query_light()
{
  return 1;
}

 

