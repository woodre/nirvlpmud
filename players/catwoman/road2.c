inherit "room/room";


reset(arg)
{
  if (arg) return;

  set_light(1);
  short_desc = "A large field";
  no_castle_flag = 0;
                                                         
  long_desc = "A large mansion is located north.\n"+"A large open grassy field with a large doorway floating in mid air .\n"+"with the word ENTER on it.\n"+"to the north will take you around the mansion.\n";
/*  dest_dir =
   ({ "room/eastroad1", "west", });*/

}

init ()
   {
  add_action("enter", "enter");
  add_action("west", "west");
  add_action("north", "north");
/*
    return;
 */
  }
north(){
call_other(this_player(), "move_player", "north#players/catwoman/a");
return 1;
}
west(){
call_other(this_player(), "move_player", "west#room/eastroad1");
return 1;
}
enter()               
 {
    write("The whole world goes a black.\n");
    call_other(this_player(), "move_player", "in#players/catwoman/hall2");
    return 1;
  }

query_light()
{
  return 1;
}

 

