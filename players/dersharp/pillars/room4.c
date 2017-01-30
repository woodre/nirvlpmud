inherit "room/room";
int i;
reset(arg) {
        if(!present("bat")) {
        for(i=0;i<8;i++) {
           move_object(clone_object("players/dersharp/monsters/bat"), this_object());
        }
   }
        if(!arg) {
                set_light(1);
        short_desc ="The entrance";
        long_desc ="	You find a way down into a dark opening in between\n"+
                   "two of the larger pillars......\n"+
                   "The smell that surrounds this place is horrible. You \n"+
                   "want to leave, but the evil MUST be eradicated!\n";
        dest_dir = ({

                "players/dersharp/pillars/room3.c", "north",
                "players/dersharp/pillars/roomst1.c", "south",
                });

        }
}
