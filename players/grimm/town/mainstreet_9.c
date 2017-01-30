inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main Street";
    no_castle_flag = 0;
    long_desc = 
"You are on the main street of ReesePort.  To the northwest you can see the\n"
        + "town's bank and to the west you can see an old beat up building\n"
        + "with the word SAGE inscribed on a sign above the door.\n";
    dest_dir = 
        ({
         "players/grimm/town/mainstreet_7", "north",
         "players/grimm/town/sage_room", "west",
        });
}

