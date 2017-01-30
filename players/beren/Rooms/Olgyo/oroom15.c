inherit "room/room";
object h, h1, h2;
reset (arg) {
  if(arg) return;
h = clone_object ("players/beren/Monsters/Olgyo/woman.c");
move_object (h, this_object ());
/*
h1 = clone_object ("players/beren/Monsters/Olgyo/woman.c");
move_object (h1, this_object ());
h2 = clone_object ("players/beren/Monsters/Olgyo/woman.c");
move_object (h2, this_object ());
*/

    set_light(1);
    short_desc = "Village of Zgama";
    long_desc =
"Here is the place where you can see Zgama's wifes. You can't\n"+
"reach Zgama before you destroy all of them!\n";
    dest_dir = ({"players/beren/Rooms/Olgyo/oroom17", "north",
                 "players/beren/Rooms/Olgyo/oroom14", "south",
                 "players/beren/Rooms/Olgyo/oroom16", "west"});

}

init ()
{
    ::init ();
    add_action ("my_north", "north");
}

my_north (str)
{
    if (present ("woman")) {
            write ("Woman won't let you pass to her husband!\n");
            return 1;
    }
}
