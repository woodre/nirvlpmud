inherit "room/room.c";
object mtest;
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "ACME marble factory";
    long_desc = 
        "Walking in, you notice a bunch of 40 year olds playing with\n" 
        + "marbles. It looks like they are testing them for strength.\n"
        + "I don't think they want to be disturbed...\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/marble1.c", "north",
        });
    mtest = clone_object("/players/wizardchild/monsters/mtest.c");
    move_object(mtest, this_object());
    mtest = clone_object("/players/wizardchild/monsters/mtest.c");
	move_object(mtest, this_object());
}
