

inherit "room/room";
object frog;

reset(arg) {
    if (arg) return;

frog = clone_object("players/morgoth/MONSTERS/tfrog");
move_object(frog, this_object());
    set_light(1);
    short_desc = "Strawberry Fields";
    no_castle_flag = 0;
    long_desc = 
    "Strawberry Fields !\n"+
        "The place where nothing is real.\n"
        + "And nothing to get hung about !\n"
        + "\n"
        + "Strawberry Fields forever !!\n";
    dest_dir = 
        ({
        "players/morgoth/CASTLE/pen_lane2", "north",
        "players/morgoth/CASTLE/field5", "west",
        "players/morgoth/CASTLE/field2", "south",
        });
}

query_light() {
    return 1;
}
