inherit "room/room";
object h, h1, h2;
reset (arg) {
  if(arg) return;
h1 = clone_object ("players/beren/Monsters/Olgyo/warrior.c");
move_object (h1, this_object ());
/*
h2 = clone_object ("players/beren/Monsters/Olgyo/warrior.c");
move_object (h2, this_object ());
h = clone_object ("players/beren/Monsters/Olgyo/warrior.c");
move_object (h, this_object ());
*/

    set_light(1);
    short_desc = "Village of Zgama";
    long_desc =
"You've just entered the Village of Zgama. It's very dangerous place.\n"+
"Olgyo aren't very friendly here. You can see some warriors. The best\n"+
"you can do - don't trouble them!\n";
    dest_dir = ({"players/beren/Rooms/Olgyo/oroom9", "east",
                 "players/beren/Rooms/Olgyo/oroom11", "west",});
}
