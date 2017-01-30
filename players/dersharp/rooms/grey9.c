inherit "room/room";
int i;
reset(arg) {
        if(!present("orc")) {
        for(i=0;i<3;i++) {
           move_object(clone_object("players/dersharp/monsters/student"), this_object());
}
}
        if(!arg) {
                set_light(1);
   short_desc="University Street";
   long_desc ="To the east is a big house with vines growing all over it.\n"+
              "To the west and north is the university while to the south\n"+
              "you can catch a glimpse of what looks like a bazaar.\n";
   dest_dir =
   ({
             "players/dersharp/rooms/grey8.c", "west",
             "players/dersharp/rooms/grey12.c", "south",
   });
}
}
init() {
    ::init();
    add_action ("Enter", "east");
}
Enter() {
      say (this_player()->query_name() + " tries to enter the house.\n");
      write("You cannot seem to get in this way.\n");
      return 1;
}
