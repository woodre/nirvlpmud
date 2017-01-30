inherit "room/room";
object obj;
reset(arg) {
  if(!arg){
set_light(1);
short_desc="Bottom of the Chasm";
long_desc=
"You shiver at the thought of just how close you came to dying.\n"+
"If it wasn't for this tiny ledge you would have fallen to your doom.\n"+
"There is a narrow trail that leads down from here, and it is only\n"+
"a short climb back up to the top of the chasm.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/path3", "up",
});

   }
}

query_ilstkarn(){ return "chasm"; }
/* realm(){ return "NT"; } */
query_nofollow(){ return 1; }

init() {
  ::init();
  add_action("down","down");
}

down() {
/*
  if(this_player()->query_level() < 21) {
	write("You decide that would not be a good idea at this time.\n");
	write("Try again later.\n");
	return 1;
  }
*/
  this_player()->move_player("down#players/pavlik/ilstkarn/fall1");
  return 1;
}

