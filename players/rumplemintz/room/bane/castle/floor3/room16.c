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
                "players/rumplemintz/room/bane/castle/floor3/room15","northwest",
                "players/rumplemintz/room/bane/castle/floor3/room17","southwest",
        });
        }
}
init() {
  ::init();
    add_action("southwest", "southwest");
}
southwest() {
  if(present("leader")) {
    write("The Leader blocks your way.\n");
    return 1;
  }
}
