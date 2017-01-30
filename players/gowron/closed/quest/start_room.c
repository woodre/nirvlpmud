inherit "room/room";

string realm() { return "NT"; }


reset(arg) {
	object guard;
	if (arg) 
	   return;
	set_light(1);
	short_desc = "Springfield Nuclear Plant";
	long_desc = "You are at the enterance to the nuclear power plant.  "+
		    "As you look to your left you see one of the cooling"+
		    "towers.  You notice a large crack in it being sealed "+
		    "together by bubble gum.  Some evil force draws you towards "+
		    "the door.\n"+
		    "Type 'in' to begin the quest..\n";
	long_desc = format(long_desc, 75);
        dest_dir = ({ "players/gowron/room/plot", "west", });

	guard = clone_object("players/gowron/closed/quest/guard");
	move_object(guard, this_object());
}


query_no_fight(){ return 1; }
