inherit "room/room";
object sci;
int B;   /*  book variable  */

init() {
	::init();
  add_action("search","search");
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return 0;
	sci=clone_object("/players/dragnar/WasteLands/mons/sci.c");
	move_object(sci, this_object());
set_light(1);
B = 1;
short_desc=("Wastelands town");
long_desc=
"It looks almost like someone has been living here.  There is a campfire\n"+
"toward the corner of one room, and some pieces of plastic and\n"+
"sheeting are put up like it was meant to be a barrier.  Farther\n"+
"back in the room is pure darkness where the light from the coals can't\n"+
"reach.  The wasteland's daylight isn't much different from its night.\n",
items=
({
"darkness","You strain your eyes and notice a man hiding in the darkness",
"campfire","You can't be sure, but it looks like something is in there",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/town4.c","south",
});
}

search(str) {
if(present("man")) {
  write("Something from the darkness whispers 'STOP!'\n");
  return 1; }
if(!str) { write("Search what?\n"); return 1; }
if(str != "campfire") {
  write("You search the "+str+" and find nothing.\n");
  return 1; }
if(str == "campfire" && B == 1) {
  write("You search the campfire and find a book hidden under\n"+
    "one of the stones.\n");
  move_object(clone_object("players/dragnar/WasteLands/obj/quest/book.c"),this_player());
  B = 0;
  return 1; }
else {
  write("You search the campfire and find nothing but ashes.\n");
  return 1; }
}
