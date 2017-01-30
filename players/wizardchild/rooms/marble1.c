inherit "room/room.c";
int i;
object ob;
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "The Main Lobby";
    long_desc = 
        "As you walk into this building, you see that the ground is made\n" 
        + "of crushed marbles. Apparently, this is a marble factory. You\n"
        + "could probably find a receptionist if you were to 'ring bell'.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/acme1.c", "east",
        "/players/wizardchild/rooms/mfloor.c", "west",
        "/players/wizardchild/rooms/moffice.c", "north",
        "/players/wizardchild/rooms/mtest.c", "south",
        });
}
init() {
        add_action("ring", "ring");
        ::init();
}
ring(st) {
        if(st != "bell") return 0;
        write("You ring the bell. A few moments later, a cow walks over to you.\n");
        ob = present("cow", environment(this_player()));
        if(ob) {
                write("There is allready one here dufus!\n");
                return 1;
        } else {
                if(i > 3) {
                        write("Sorry, all of our receptionists have been butchered.\n");
                        return 1;
                } else {
                        ob = clone_object("/players/wizardchild/monsters/cow.c");
                        move_object(ob, this_object());
                        i += 1;
                        return 1;
                }
        }
}
