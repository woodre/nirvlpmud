

inherit "room/room";
object berries;

reset(arg) {
    if (arg) return;

berries=clone_object("players/morgoth/OBJ/berries");
move_object(berries, this_object());
    set_light(1);
    short_desc = "Strawberry Fields";
    no_castle_flag = 0;
    long_desc = 
"Strawberry Fields forever....\n";
    dest_dir = 
        ({
        "players/morgoth/CASTLE/field9", "east",
        "players/morgoth/CASTLE/Efield14", "south",
        });
}

query_light() {
    return 1;
}
