inherit "room/room.c";
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "ACME Plaza";
    long_desc = 
        "This is the end of ACME Plaza. It appears that going further\n" 
        + "to the south would take you into the countryside. Of to the\n"
        + "east and west are shops.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/marbles.c", "west",
        "/players/wizardchild/rooms/nukes.c", "east",
        "/players/wizardchild/rooms/acme1.c", "north",
        "/players/wizardchild/rooms/side1.c", "south",
        });
}
