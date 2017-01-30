inherit "room/room";

reset(arg){

	if (!arg) {
	set_light(1);
	short_desc = "room east south 3";
	long_desc = 
	"The shadows of the dark dwells every which way.\n"+
	"The air smells like formaldehyde...a pungent odor\n"+
	"stinging your nose emanating from the south. \n";
        dest_dir = ({"players/airwoman/CASTLE/rmes2", "north",
        "players/airwoman/CASTLE/rmes4", "south"});
}
}
