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
                      "of bone!  The exit to the east is guarded by the \n"+
                      "monstrosity!.....so KILL IT!\n";
        dest_dir = ({
                     "players/dersharp/pillars/roomst6.c", "south",
                     "players/dersharp/pillars/room2.c", "east",
                });
        }
}
init() {
    ::init();
    add_action ("east", "east");
}
east() {
      if(present("dragon")) {
        write("The dragon bars your way.\n");
       return 1;
}
       return 0;
}
