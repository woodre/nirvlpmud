inherit "room/room";
object dog4;

reset(arg)
{
  if (!dog4) {
	dog4 = clone_object("/players/catwoman/monster/dog");
	move_object(dog4, this_object());
	}
  if (arg) return;

  set_light(1);
  short_desc = "---Cobble stone path---";
  no_castle_flag = 0;
                                                         
  long_desc = "A Cobble stone path\n"+"obvious exit is west.\n";

}

init ()
   {
  add_action("west","west");
  add_action("dig","dig");
  }
west(){
call_other(this_player(), "move_player", "west#players/catwoman/d");
return 1;
}

query_light()
{
  return 1;
}

dig() {
if(present("dog")) {
  write("The guard dog snarls and bares its teeth!\n"); return 1; }
if(!present("shovel",this_player())) {
  write("The ground is much too hard without a shovel.\n");
  return 1; }
else {
  write("You dig around the end of the cobblestone path and find nothing.\n");
  return 1; }
}
