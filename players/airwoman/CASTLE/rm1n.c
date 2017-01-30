inherit "room/room";

reset(arg){
   if (!arg){
	set_light(1);
	short_desc = "1st room north of entrance";
	long_desc = 
	"A clean well lighted place that Hemingway would like.\n"+
        "Looking to the west you see a drug store?\n";

	dest_dir =
        ({"players/airwoman/CASTLE/phcy", "west",
	"players/airwoman/CASTLE/rm2n", "north",
        "players/airwoman/CASTLE/entrance", "south"});
}
}
