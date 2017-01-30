inherit "room/room";
int i;
reset(arg) {
        if(!arg) {
                set_light(1);
         short_desc = "Descent into Doom";
         long_desc = "Before you lies a great stairway which goes upward.\n"+
                     "To the west is a room that you sense as having great \n"+
                     "evil within, dread carefully!\n";
        dest_dir = ({

                "players/dersharp/pillars/roomst3.c", "up",
                "players/dersharp/pillars/room47.c", "west",
                });
}
}
