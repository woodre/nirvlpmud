inherit "room/room";
reset(arg){
  if(!present("leader")) {
    move_object(clone_object("players/rumplemintz/mon/bane/sklead"), this_object());
    }
        if(!arg){
        set_light(1);
        short_desc="A Corridor";
        long_desc="Yup, you're still in the drab hallway, better get used to it, cause\n"+
                "that's all there is up here on the third level too.\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor3/room4","southwest",
                "players/rumplemintz/room/bane/castle/floor3/room6","east",
        });
        }
}
init() {
  ::init();
    add_action("east", "east");
}
east() {
  if(present("leader")) {
    write("The Leader blocks your way.\n");
    return 1;
  }
}