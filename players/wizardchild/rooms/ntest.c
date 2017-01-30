inherit "room/room.c";
object ntest;
object nthrow;
object nmut;
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "ACME nuclear test facility";
    long_desc = 
        "You feel a wave of heat hit you as you enter.\n" 
        + "This is ACME's very own nuclear test facility. Here, it appears,\n"
        + "volunteers practice jumping on nuclear handgrenades to dampen the.\n"
        + "force of the explosions.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/nuke.c", "west",
        });
    ntest = clone_object("/players/wizardchild/monsters/ntest.c");
    move_object(ntest, this_object());
    nthrow = clone_object("/players/wizardchild/monsters/nthrow.c");
    move_object(nthrow, this_object());
    nmut = clone_object("/players/wizardchild/monsters/nmut.c");
    move_object(nmut, this_object());
}
