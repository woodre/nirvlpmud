inherit "room/room";
object h, h1, h2;

reset(arg) {
  if(arg) return;
    h = clone_object ("players/beren/Monsters/Olgyo/hunter.c");
    move_object (h, this_object());
/*
    h1 = clone_object ("players/beren/Monsters/Olgyo/hunter.c");
    move_object (h1, this_object ());
    h2 = clone_object ("players/beren/Monsters/Olgyo/hunter.c");
    move_object (h2, this_object ());
*/
    if (arg) return;

    set_light(1);
    short_desc = "Olgyo Hunter's domain";
    long_desc =
"You are standing in the deep forest. All around is unknown for you.\n"+
"The only thing you know that you are on the territory of Olgyo hunters.\n"+
"You can see some of them here busy hunting.\n";
    dest_dir = ({"players/beren/Rooms/Olgyo/oroom2", "north",
	         "players/beren/Rooms/Olgyo/oroom3", "south",
		 "players/beren/Rooms/Olgyo/oroom5", "east",
		 "players/beren/Rooms/Olgyo/oroom", "west"});
}
