inherit "room/room";
object h;
reset (arg) {
  if(arg) return;
h = clone_object ("players/beren/Monsters/Olgyo/champion.c");
move_object (h, this_object ());

    set_light(1);
    short_desc = "Village of Zgama";
    long_desc =
"You managed to get to the Olgyo Champion!\n"+
"He is really strong guy, but you can't say he is bad one.\n";
    dest_dir = ({"players/beren/Rooms/Olgyo/oroom10", "east"});

}
