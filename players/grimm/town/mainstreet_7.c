inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main Street";
    no_castle_flag = 0;
    long_desc = 
"You are on the main street of ReesePort.  To the southwest,"+
"\nyou can see an old beat up building with the word SAGE inscribed on a\n"+
"sign above the door.\n";
    dest_dir = 
        ({
         "players/grimm/town/mainstreet_5", "north",
         "players/grimm/town/mainstreet_9", "south",
        });
}

