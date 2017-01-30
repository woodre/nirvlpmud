

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
        "players/morgoth/CASTLE/field4", "east",
        "players/morgoth/CASTLE/field12", "west",
        });
}

query_light() {
    return 1;
}
