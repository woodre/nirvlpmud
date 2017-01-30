inherit "room/room";
object corridor;
reset(arg){
  if(!present("barbarian")) {
    move_object(clone_object("players/rumplemintz/mon/bane/skbarb"), this_object());
  }
        if(!arg){
        set_light(1);
        short_desc="A corridor";
        long_desc="Right when you enter this room, you notice something different\n"+
                "about it.  The walls are clean, and there is a pile of dust laying on\n"+
                "the ground.  It seems as though someone has been here to clean, but\n"+
                "only this room.  Strange.\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor2/room13","west",
        });
        items=({
	"dust", "It's a pile of dust....",
        });
        }
}
init(){
	add_action("search1"); add_verb("search");
	add_action("north"); add_verb("north");
}
search1(str){
  if(present("barbarian")){
    write("You can't search with him in here!\n");
    return 1;
    }
        if(str=="dust"){
        write("You throw the dust about the room like a child.\n");
        write("The dust clings to the walls, and you notice that there\n"+
                "to the north, is a space in the wall.  Without the dust,\n"+
                "you would've never known, that there was an exit north.\n"+
                "thank god for dusty rooms!\n");
	say(capitalize(this_player()->query_name())+" rummages through the dust pile.\n");
	corridor = this_player();
        return 1;
        }
}
north(){
  if(corridor==this_player()){
    write("You go north through the wall, into the corridor you found.\n");
    this_player()->move_player("leaves#players/rumplemintz/room/bane/castle/floor2/room15");
    return(1);
  }
  write("What?\n");
  return 1;
}
