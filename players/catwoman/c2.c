inherit "room/room";

object chisel;

reset(arg)
{

  if (!chisel) {
	chisel = clone_object("players/catwoman/weapon/chisel");
	move_object(chisel, this_object());
	}
  set_light(1);
  if (arg) return;
  short_desc = "---A closet---";
  no_castle_flag = 0;
                                                         
  long_desc = "This is where the gardener keeps his stone carving tools.\n"+"obvious exit is south.\n";

}

init ()
   {
/*    add_action ("north"); add_verb ("north");
    add_action ("west"); add_verb ("west");*/
    add_action ("south","south");
    return;
  }
south(){
call_other(this_player(), "move_player", "south#players/catwoman/mirror3");
return 1;
}

query_light()
{
  return 1;
}

 

