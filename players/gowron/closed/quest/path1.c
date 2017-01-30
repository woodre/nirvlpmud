inherit "room/room";

reset(arg) {
	if (arg)
           return;
	set_light(1);
	short_desc = "Path by cooling tower";
	long_desc = "You are heading down a path around the cooling tower. "+
		    "The close view of the tower gives you an accurate "+
		    "representation of just how poorly maintained this "+
		    "facility is.  One small leak in the tower catches "+
		    "your attention.  The leak goes down the tower, and "+
		    "into the river on your left.  As you look down at "+
		    "your feet you notice that you are stepping in the "+
		    "leakage.\n";
	items = ({ "leakage", "It is some sort of radioactive ooze", });
	long_desc = format(long_desc, 75);
	dest_dir = ({ "players/gowron/room/plot", "back",
		      "players/gowron/closed/quest/sroom", "continue", });
}

	
