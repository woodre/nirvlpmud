inherit "room/room.c";
object nchick;
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "ACME nuclear handgrenade factory";
    long_desc = 
        "Hanging by strings above your head are various types of handgrenades,\n" 
        + "some of which are 4' in diameter. These handgrenades look very effective,\n"
        + "though the might be a bit tough to throw.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/ntest.c", "east",
        "/players/wizardchild/rooms/acme1.c", "west",
        });
    nchick = clone_object("/players/wizardchild/monsters/nchick.c");
    move_object(nchick, this_object());
}
