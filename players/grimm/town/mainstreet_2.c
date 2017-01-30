inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main Street";
    no_castle_flag = 0;
    long_desc = 
    "You are on the main street of ReesePort.\n";
    dest_dir = 
        ({
         "players/grimm/town/mainstreet_1", "west",
         "players/grimm/town/mainstreet_3", "east",
        });
}
