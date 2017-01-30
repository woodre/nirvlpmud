inherit "room/room";
int i;
reset(arg) {
        if(!present("baltek")) {
           move_object(clone_object("players/dersharp/monsters/skeld"), this_object());
        }
        if(!arg) {
                set_light(1);
        short_desc ="The Dragon room";
         long_desc = "A dragon's den, except that the dragon is made out\n"+
                      "of bone!  The exit to the south is guarded by the \n"+
                      "monstrosity!.....so KILL IT!\n";
        dest_dir = ({
                     "players/dersharp/pillars/roomst4.c", "east",
                     "players/dersharp/pillars/room48.c", "south",
                });
        }
}
init() {
    ::init();
    add_action ("south", "south");
}
south() {
      if(present("dragon")) {
        write("The dragon bars your way!\n");
       return 1;
}
       return 0;
}
