inherit "room/room.c";
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "ACME Plaze";
    long_desc = 
        "Looking around, you see many large buildings and shops. It\n" 
        + "looks like this is the main headquarters for ACME Inc. Off\n"
        + "to your east and west lie office buildings.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/marble1.c", "west",
        "/players/wizardchild/rooms/nuke.c", "east",
        "/players/wizardchild/rooms/entry.c", "north",
        "/players/wizardchild/rooms/acme2.c", "south",
        });
}
