inherit "room/room";

int foundring;

reset(arg)
{
  if (arg) return;

  set_light(1);
  short_desc = "---Cobble stone path---";
  no_castle_flag = 0;
                                                         
  long_desc = "A Cobble stone path\n"+"obvious exit is west.\n";

}

init ()
   {
    add_action ("west","west");
	add_action("dig","dig");
    return;
  }
west(){
call_other(this_player(), "move_player", "west#players/catwoman/e");
return 1;
}

query_light()
{
  return 1;
}

dig() {
object ob,ring;
ob = present("shovel",this_player());
if(!ob) {
  write("The ground is too hard without a shovel.\n"); return 1; }
if( (ob) && present("clamnote",this_player())) {
  if(foundring) {
    write("You find nothing.\n"); return 1; }
  write("You dig just off the end of the cobblestone path and find\n"+
	"an interesting item.\n");
  ring = clone_object("players/catwoman/armor/ring.c");
  move_object(ring,this_player());
  foundring = 1;
  return 1; }
else {
  write("You dig but without following the quest steps you find nothing.\n");
  return 1; }
}
