inherit "room/room";
object corridor;
reset(arg){
        if(!arg){
        set_light(1);
        short_desc="Nowhere";
        long_desc="  As you assault the mighty stairway, (notice the tiredness of\n"+
                "the coder, and his lack of imagination), you find, that this is just\n"+
                "another corridor, plain as a baby's butt, except it's the third floor.\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor2/room15","down",
        });
        }
}
init() {
  ::init();
    add_action("search1", "search");
    add_action("east", "east");
}
search1(){
  write("You search the room frantically, and find an exit to the east.\n");
  say(capitalize(this_player()->query_name())+" searches about madly.\n");
  corridor = this_player();
  return 1;
}
east() {
  if(corridor==this_player()){
    write("You go east through the secret exit you found, and enter level III.\n");
    this_player()->move_player("leaves#players/rumplemintz/room/bane/castle/rfloor3/room2");
    return(1);
    }
  write("What?\n");
  return 1;
}
