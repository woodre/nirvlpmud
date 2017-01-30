inherit "room/room";
int i;
reset(arg) {
        if(!present("troglodyte")) {
        for(i=0;i<4;i++) {
        move_object(clone_object("players/dersharp/monsters/trog"), this_object());
        }
   }
        if(!arg) {
                set_light(1);
        short_desc ="A dimly lit room";
        long_desc ="	The lights are dimmer in this part of the dungeon\n"+
                   "and you feel very much like running.  Yet you remain,\n"+
                   "your heart steeled against the gloom....for now...\n";
        dest_dir = ({

                "players/dersharp/pillars/room22.c", "north",
                "players/dersharp/pillars/room26.c", "west",
                });

        }
}
