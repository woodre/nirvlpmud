inherit "room/room";
int i;
reset(arg) {
        if(!present("lea")) {
        move_object(clone_object("players/dersharp/monsters/lea"), this_object());
        if(arg) return;
        set_light(1);
        short_desc ="A dimly lit room";
        long_desc ="Up on this second level the monsters do not seem as hard\n"+
                   "yet there are more of them.  This room is damp with bits\n"+
                   "of unidentifiable matter everywhere.  Along the north\n"+
                   "wall there seems to be something different.\n";
        dest_dir = ({
                "players/dersharp/pillars/room31.c", "west",
                "players/dersharp/pillars/room35.c", "south",
                });
        }
}
init() {
    ::init();
    add_action ("Search", "search");
}
Search() {
      say(this_player()->query_name() + " enters the northern wall.\n");
      write ("You find a secret passage to the north and decide to take it.\n");
      move_object(this_player(), "players/dersharp/pillars/room43.c");
      command("look",this_player());
      return 1;
}
