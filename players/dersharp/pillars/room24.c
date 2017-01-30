inherit "room/room";
int i;
reset(arg) {
        if(!present("baltek")) {
           move_object(clone_object("players/dersharp/monsters/baltek"), this_object());
        }
        if(arg) return;
                set_light(1);
         short_desc = "A musty room";
        long_desc ="The aura of evil has increased. Looking around this room\n"+
                   "you notice that many of the rocks in the eastern wall\n"+
                   "seem to be out of place.\n";
        dest_dir = ({
                     "players/dersharp/pillars/room20.c", "north",
                });

        }
init() {
    ::init();
    add_action ("Search", "search");
}
Search() {
      say(this_player()->query_name() + " enters the eastern wall.\n");
      write ("You find a secret passage to the east and decide to take it.\n");
     move_object(this_player(), "players/dersharp/pillars/room25.c");
     command("look",this_player());
      return 1;
}
