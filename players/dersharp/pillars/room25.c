inherit "room/room";
int i;
reset(arg) {
        if(!present("orc")) {
        for(i=0;i<3;i++) {
           move_object(clone_object("players/dersharp/monsters/ogre"), this_object());
        }
   }
        if(!arg) {
                set_light(1);
        short_desc ="Danger Zone!";
        long_desc ="	This is where some of the hardest monsters live.\n"+
                   "If you are under level 4 you had better leave.  If \n"+
                   "not, enjoy!\n";
        dest_dir = ({

                "players/dersharp/pillars/room24.c", "west",
                "players/dersharp/pillars/roomst3.c", "south",
                });

        }
}
