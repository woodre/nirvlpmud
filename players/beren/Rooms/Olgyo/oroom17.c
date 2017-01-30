inherit "room/room";
object h;
reset (arg) {
  if(arg) return;
h = clone_object ("players/beren/Monsters/Olgyo/zgama.c");
move_object (h, this_object ());

    set_light(1);
    short_desc = "Village of Zgama";
    long_desc =
"You are in the small hut. You can see Zgama in the middle of\n"+
"the room. He just doesn't like you here! You etter get out fast\n";
    dest_dir = ({"players/beren/Rooms/Olgyo/oroom15", "south"});

}
