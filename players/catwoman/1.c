inherit "room/room";
object gardener;

reset(arg)
{
	if (!gardener) {
	gardener = clone_object("/players/catwoman/monster/gardener");
	move_object(gardener, this_object());
	}
  if (arg) return;

  set_light(1);
  short_desc = "---Gardener's shack---";
  no_castle_flag = 0;
                                                         
  long_desc = "Gardener's shack\n"+"This is the main room of the gardener's shack.\n"+"obvious exits are west and east.\n";

}

init ()
   {
/*    add_action ("north"); add_verb ("north");*/
    add_action ("west","west");
    add_action ("east","east");
    return;
  }
west(){
call_other(this_player(), "move_player", "west#players/catwoman/city/doom/room");
return 1;
}
east(){
if(present("gardener")) {
  write("The gardener puts out his arm and says, 'sorry, you can't go\n"+
	"that way.....it's private.'\n");
  return 1; }
else {
call_other(this_player(), "move_player", "east#players/catwoman/2");
return 1; }
}


query_light()
{
  return 1;
}

 

