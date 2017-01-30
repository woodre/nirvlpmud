inherit "room/room.c";
object mpres;
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "ACME marble plant";
    long_desc = 
        "As you look around, you see the pictures of many great morons\n" 
        + "hanging on the walls. This, most likely, is the office for the\n"
        + "President of ACME Marbles Inc.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/marble1.c", "south",
        });
        mpres = clone_object("/players/wizardchild/monsters/mpres.c");
        move_object(mpres, this_object());
}
