inherit "room/room";
object chest;
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
  object chest;
  
	chest = present("chest", this_object() );
  if( chest ) 
    chest->reset( arg );
  
  if(arg) return;
  
  if( !chest ) {
    chest=clone_object("players/dragnar/WasteLands/obj/quest/chest.c");
	  move_object(chest, this_object());
  }
  
set_light(0);
short_desc=("Wasteland's library");
long_desc=
"It is pitch black down here.  There is garbage flung across the room and\n"+
"old equipment that once was used to keep the library in working condition.\n"+
"The only thing that catches your eye is a chest on the other side of the\n"+
"room.  There is a satanic symbol on the wall just above it.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/base2.c","up",
});
}
