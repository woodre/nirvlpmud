inherit "room/room";

object yonson;
reset(arg){
	if (!present("yonson")) {
       move_object(clone_object("players/airwoman/MONSTER/yonson"),this_object());
	}

	if (!arg){
	   set_light(1);
        short_desc = "room east south 1" ;
	long_desc=
	"Remember Slaughter House Five?\n"+
	"WWII The bombing of Dresden Germany...\n"+
	"And so it goes...\n";
        dest_dir = ({"players/airwoman/CASTLE/rm5e", "north",
	"players/airwoman/CASTLE/rmes2", "south"});

}
}
