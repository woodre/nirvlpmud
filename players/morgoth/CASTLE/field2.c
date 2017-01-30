

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
        "players/morgoth/CASTLE/field1", "north",
        "players/morgoth/CASTLE/field6", "west",
        "players/morgoth/CASTLE/field3", "south",
        });
}

query_light() {
    return 1;
}
