inherit "room/room";
int i;
reset(arg) {
        if(!present("orc")) {
            for(i=0;i<2;i++) {
	move_object(clone_object("players/rumplemintz/mon/kor/korc"), this_object());
        }
    }
        if(!arg) {
                set_light(1);
        short_desc = "The land of the Orcs of Kor";
        long_desc = "     This is the outter most boundary to the Orcs of Kor's land\n"+
                "possesions.  There are two Orcs guarding the boundary.  You might be\n"+
                "able to slip by them, for they aren't totally awake.\n";

        dest_dir = ({

		"players/rumplemintz/room/klanding", "west",
                "players/rumplemintz/room/kor/magicshop", "east",
                "players/rumplemintz/room/kor/room2", "northeast",
                "players/rumplemintz/room/kor/room4", "southeast",
                });

        }
}
init(){
    ::init();
    add_action("no_ent","east");
    add_action("no_ent","northeast");
    add_action("no_ent","southeast");
}
no_ent(){
  if(this_player()->query_level() > 5){
    write("You are too experienced for this realm.\n");
    return 1;
  }
}
