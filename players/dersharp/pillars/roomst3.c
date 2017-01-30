inherit "room/room";
int i;
reset(arg) {
        if(!arg) {
                set_light(1);
         short_desc = "Descent into Doom";
         long_desc = "Before you lies a great stairway which goes downward.\n"+
                     "The evil emanating from it causes you to reconsider\n"+
                     "your reason for being here.  Down those steps, you\n"+
                     "know are some of the most dangerous foes you have \n"+
                     "yet to encounter...\n";
        dest_dir = ({

                "players/dersharp/pillars/roomst4.c", "down",
                "players/dersharp/pillars/room25.c", "north",
                });

        }
}
