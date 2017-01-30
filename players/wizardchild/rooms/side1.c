inherit "room/room.c";
object cow;
object dcow;
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "The Countryside";
    long_desc = 
        "As you walk past town, you notice an sudden abundance of farm\n" 
        + "animals all over the place. A group of cows drives by in a\n"
        + "gangster car trying to sell sugar cubes.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/side2.c", "south",
        "/players/wizardchild/rooms/acme2.c", "north",
        });
    cow = clone_object("/players/wizardchild/monsters/cow.c");
    call_other(cow, "set_long", "A teenaged cow. He is obviously being pressed to try\n"
                                +"sugar by the sugar dealer here...\n");
    move_object(cow, this_object());
    dcow = clone_object("/players/wizardchild/monsters/dcow.c");
    move_object(dcow, this_object());
}
