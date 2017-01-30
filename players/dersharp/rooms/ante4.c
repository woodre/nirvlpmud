inherit "room/room";
int i;
reset(arg) {
        if(!present("orc")) {
        for(i=0;i<3;i++) {
           move_object(clone_object("players/dersharp/monsters/rat"), this_object());
}
}
        if(!arg) {
   short_desc="A side room";
   long_desc ="This is a small room off the main corridor.  It seems empty\n"+
              "and on top of that it smells something awful!  There seems\n"+
              "to be a leak in one of the pipes coming from the lavitory\n"+
              "and is spilling a liquid on the floor\n";
set_light(1);
dest_dir =
 ({
          "players/dersharp/rooms/hall2.c", "west",
});
}
