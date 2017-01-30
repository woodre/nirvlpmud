

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Inside a Dark Cave";
    no_castle_flag = 0;
    long_desc =
	  "You've reached the back of the cave. Before you is a huge wall\n"
	+ "carved out of the earth. You think you hear something ahead and\n"
	+ "above you, but you can't quite make it out. As you look more\n"
	+ "closely at the wall you think that you can make out foot-holds\n"
	+ "in the stone. How odd.\n";
items = ({
	"foot-holds", "Large foot-holds that look like they could support "
		+"a full-grown orc.\nPerhaps you could climb the wall",
});
    dest_dir =
        ({
        "players/pain/NEW/cave2", "out",
        });
if(!present("orc"))
{
move_object(clone_object("/players/pain/NEW/mon/orc_g"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_g"),this_object());
}
}

init() {
	::init();
add_action("climb", "climb");
}

climb(str) {
if(!str) {
	write("What would you like to climb?\n");
	return 1;
}
if(str != "wall") {
	write("You can't climb that!\n");
	return 1;
}
write("You approach the wall and begin to climb up it.\n");
write("As you near the ceiling you see a hole cut in it leading into a room.\n");
write("You enter the room through the hole in the ceiling.\n");
move_object(this_player(),"/players/pain/NEW/lair1.c");
command("look", this_player());
tell_object(this_object(),this_player()->query_real_name()+" leaves through a hole in the ceiling.\n");
return 1;
}

realm() { return "NT"; }


query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}

/*
    remove the comments around the "room is modified()" code
    below to prevent changes you have done to this room to
    to be lost by using the room maker
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

