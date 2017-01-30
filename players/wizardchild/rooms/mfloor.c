inherit "room/room.c";
object mjerk;
object mwork;
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "ACME marble plant";
    long_desc = 
        "This is the main floor, where the marbles are actually produced.\n" 
        + "While looking around, you notice that one of the plant workers\n"
        + "seems unhappy. He is shooting people with a marble gun.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/marble1.c", "east",
        });
        mjerk = clone_object("/players/wizardchild/monsters/mjerk.c");
        move_object(mjerk, this_object());
        mwork = clone_object("/players/wizardchild/monsters/mwork.c");
        move_object(mwork, this_object());
        mwork = clone_object("/players/wizardchild/monsters/mwork.c");
        move_object(mwork, this_object());
}
