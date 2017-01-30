inherit "room/room";
object corridor;
int i;
reset(arg){
    if(!present("barbarian")){
	for(i=0;i<3;i++){
	    move_object(clone_object("/players/rumplemintz/mon/bane/skbarb"), this_object());
	}
    }
    if(arg) return;
    ::reset(arg);
    set_light(1);
    short_desc="Bane's Castle";
    long_desc="    You are wandering through Bane's castle, notice that in  every\n"+
    "room, there are some of Bane's servants here, making you feel not so\n"+
    "welcome.  You can't help but wonder why they aren't attacking you,\n"+
    "maybe they have something planned...\n";
    dest_dir=({
      "players/rumplemintz/room/bane/castle/floor1/room35","east",
      "players/rumplemintz/room/bane/castle/floor1/room41","south",
      "players/rumplemintz/room/bane/castle/floor1/room40","southwest",
      "players/rumplemintz/room/bane/castle/floor1/room26","northwest",
      "players/rumplemintz/room/bane/castle/floor1/room33","west",
      "players/rumplemintz/room/bane/castle/floor1/room42","southeast",
      "players/rumplemintz/room/bane/castle/floor1/room28","northeast",
      "players/rumplemintz/room/bane/castle/floor1/room27","north",
    });
}
init() {
    ::init();
    add_action("search1", "search");
    add_action("up", "up");
}
search1() {
    write("After a great deal of searching, you pull a large black switch\n"+
      "and see a staircase drop from the ceiling.\n");
    say(capitalize(this_player()->query_name())+" searches frantically.\n");
    corridor=this_player();
    return 1;
}
up() {
    if(corridor==this_player()){
	write("You go up the staircase, to the next level that you found.\n");
	this_player()->move_player("leaves#players/rumplemintz/room/bane/castle/floor2/room1");
	return(1);
    }
    write("What?\n");
    return 1;
}
