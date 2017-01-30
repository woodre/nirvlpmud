

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Strawberry Fields";
    no_castle_flag = 0;
    long_desc = 
"Strawberry Fields forever....\n";
    dest_dir = 
        ({
        "players/morgoth/CASTLE/field1", "east",
        "players/morgoth/CASTLE/field9", "west",
        "players/morgoth/CASTLE/field6", "south",
        });
}

query_light() {
    return 1;
}
