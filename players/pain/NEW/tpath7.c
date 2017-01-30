

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The End of The Twisting Path";
    no_castle_flag = 0;
    long_desc =
        "You are well north of a small clearing containing a cave.\n"
        + "The trees tower over you and the mountains loom over the forest\n"
        + "to the west. All about you is nature.\n"
	+ "\n\nA shimmering portal\n";

items = ({
	"path", "A narrow, muddy path through the forest",
	"portal", "A shimmering portal, perhaps you could enter it",
});
    dest_dir =
        ({
        "players/pain/NEW/tpath6", "south",
        });
if(!present("worker"))
{
move_object(clone_object("/players/pain/NEW/mon/worker"),this_object());
move_object(clone_object("/players/pain/NEW/mon/worker"),this_object());
}
if(!present("footman"))
{
move_object(clone_object("/players/pain/NEW/mon/footman"),this_object());
move_object(clone_object("/players/pain/NEW/mon/footman"),this_object());
}
}

init() {
	::init();
add_action("enter", "enter");
}

enter(str) {
	if(!str) {
		write("Enter what?\n");
		return 1;
	}
	if(str != "portal") {
		write("What do you want to enter?\n");
		return 1;
	}
	write("\n\n");
	write("You are surrounded by an explosion of beautiful colors as you.\n");
	write("enter a distant world!\n");
	write("\n\n");
	call_other(this_player(), "move_player",
             "enter#players/pain/NEW/flet/entrance");
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

