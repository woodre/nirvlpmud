inherit "room/room";

string realm() { return "NT"; }

object burns,smithers;

get_smithers() {
        return clone_object("players/gowron/closed/quest/floor2/smithers");
}

reset(arg) {
	if (arg)
           return;
	set_light(1);
	short_desc = "Burns' Office";
	long_desc = "You have entered the office of C.M. Burns.  The evil "+
		    "that has spread throughout Springfield has come from "+
		    "this location.  By stopping Smithers and Burns you "+
		    "will, at least temporarily stop the evil in this "+
		    "town.  Be careful though, they won't go down easily.\n"+
		    "BTW - the only way out is to finish these two off.\n"+
		    "Type 'solve' when you have done so.\n";
	long_desc = format(long_desc, 75);
	move_object(get_smithers(), this_object());
	burns = clone_object("players/gowron/closed/quest/floor2/burns");
	move_object(burns, this_object());
}

solve_quest() {
object suit;
	if (!(present("burns") && present("smithers"))) {
	   say("Congrats you solved the quest...\n");
           destruct(present("card", this_player()));	   
	   this_player()->set_quest("springfield");
   if(suit = present("suit", this_player())){
      suit->drop();
       destruct(suit);
       }
	   this_player()->move_player("advguild#room/adv_guild");
	   return 1;
	}
	write("Stop trying to cheat....\n");
	this_player()->move_player("church#room/church");
/* changed from return; to return 1; 12/6/99 Dragnar */
   return 1;
}

init() {
	add_action("solve_quest", "solve");
}
	
