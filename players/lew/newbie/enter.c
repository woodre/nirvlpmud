

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "Entrance to Keating [nw]";
	no_castle_flag=0;
	long_desc = 
		"Before you stands a large black building.  It is Keating Hall.\n"
		+ "This is IIT's gymnasium.  Being that it is very early in the\n"
		+ "morning, most of the ROTC is conducting training in there.\n"
		+ "Chances are there are some pretty easy kills.  If you are under\n"
		+ "level 5, feel free to enter.  If not, face the wrath of 'armor'.\n";
	dest_dir = 
	    ({
	"players/lew/newbie/keating1", "west",
	"players/lew/commons", "southeast",
	});
}

query_light() {
    return 1;
}
query_room_maker() {
	return 1;
}

/*
	remove the comments around the "room is modified()" code
	below to prevent changes you have done to this room to
	to be lost useing the roommaker
*/
/*
room_is_modified() {
	return 1;
}
*/
/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

init() {
  ::init();
    add_action("check_level","west");
}

check_level() {
    if(call_other(this_player(), "query_level") > 5 ) {
      write("Captain Hearvy jumps out in front of you.\n"+
            "Captain Hearvy shouts:  Ooooohhhh no.  You're not getting in there.\n"+
            "Captain Hearvy punches you. (doing damage of course)\n");
      say("Captain Hearvy beats the shit out of "+
          capitalize(this_player()->query_real_name())+".\n");
      call_other(this_player(), "hit_player", random(20));
      return 1;
    }
    return 0;
}

