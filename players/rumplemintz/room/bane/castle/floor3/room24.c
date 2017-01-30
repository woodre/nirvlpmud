inherit "room/room";
object corridor;
reset(arg){
        if(!present("leader")){
	move_object(clone_object("players/rumplemintz/mon/bane/sklead.talk"), this_object());
        }
        if(!arg){
        set_light(1);
        short_desc="The Skull Leader";
        long_desc="Whoa! Looks like you bumped into the wrong guy, here stands the\n"+
                "Skull Leader.  He is an impressive sight, needing no armor because\n"+
                "of his strong bony build.  His only weapon, a sword in a leather\n"+
                "scabbard at his side.  The scabbard looks old and used, but you can\n"+
                "still see the shine of his sword peeking through.\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor3/room23","southwest",
        });
        }
}
init(){
        add_action("listen"); add_verb("listen");
        add_action("west"); add_verb("west");
}
listen(str){
  if(present("leader")){
    write("You can't do that while he's still here!!\n");
    return 1;
    }
        if(str=="to walls"){
        write("You place your ear to the wall, and begin to listen.\n");
	write("Walls say: To continue on, go west.\n");
	corridor = this_player();
        return 1;
  }
}
west(){
  if(corridor==this_player()){
    write("You go west through the talking walls, and find your self in a stairway.\n");
    this_player()->move_player("leaves#players/rumplemintz/room/bane/castle/floor3/room25");
    return(1);
    }
  write("What?\n");
  return 1;
}
