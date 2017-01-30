inherit "room/room";
object h, h1, h2;
reset (arg) {
if(!present("guard", this_object())) {
h = clone_object ("players/beren/Monsters/Olgyo/guard.c");
move_object (h, this_object ());
h1 = clone_object ("players/beren/Monsters/Olgyo/guard.c");
move_object (h1, this_object ());
h2 = clone_object ("players/beren/Monsters/Olgyo/guard.c");
move_object (h2, this_object ());
}
if(arg) return;

    set_light(1);
    short_desc = "Village of Zgama";
    long_desc =
"Here is an Olgyo guard outpost. Guard won't let you pass into\n"+
"the center of the village unless you are invited here. But you\n"+
"aren't are you?\n";
    dest_dir = ({"players/beren/Rooms/Olgyo/oroom15", "north",
                 "players/beren/Rooms/Olgyo/oroom9", "south"});

}

init ()
{
    ::init ();
    add_action ("my_north", "north");
}

my_north (str)
{
    if (present ("guard")) {
            write ("You aren't invited! You can't pass!\n");
            return 1;
    }
}
