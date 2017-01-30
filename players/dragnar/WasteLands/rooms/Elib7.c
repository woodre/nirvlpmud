#define shit cult=clone_object("/players/dragnar/WasteLands/mons/cult.c");
#define fuck move_object(cult, this_object());
inherit "room/room";
object cult, master;
int K;  /*  key variable so there's only one  */

init() {
	::init();
  add_action("slide","slide");
	this_player()->set_fight_area();
}
reset(arg) {
	shit
	fuck
	shit
	fuck	
	master=clone_object("/players/dragnar/WasteLands/mons/cultmaster.c");
	move_object(master, this_object());
	if(arg) return;
K = 1;  /*  key present  */
set_light(5);
short_desc=("Wasteland's library");
long_desc=
"This room seems to be another type of meeting room.  There are candles\n"+
"lighted all over the room that cast a strange glow on the room.  In\n"+
"the center of the room is a large table with an added leaf for length,\n"+
"like this might be the main meeting table.\n",
items = ({
  "table","An extra long wooden table with the additional leaf",
  "leaf","A 14 inch wide addition to make the table longer.  All one\n"+
 	"has to do is slide it into place",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/lib6.c","west",
});
}

slide(str) {
if(present("member")) {
  write("The cult member removes your hand and shakes his head.\n");
  return 1; }
if(!str) { write("Slide?\n"); return 1; }
if(str == "leaf" && K == 1) {
  write("You slide the leaf over a little and find a small key hidden\n"+
	"underneath, out of sight.\n");
  move_object(clone_object("players/dragnar/WasteLands/obj/quest/key.c"),this_player());
  K = 0;
  return 1; }
else {
  write("You slide the leaf over a little..... looks better.\n");
  return 1; }
}
