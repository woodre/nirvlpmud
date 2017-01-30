

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Inside a dark Cave";
    no_castle_flag = 0;
    long_desc =
	  "You stand just inside the entrance of the huge, forbidding\n"
	+ "cave. It is rumored that this cave contains the base of\n"
	+ "operations for the ruthless Blood Fisted Clan.\n\n"
	+ "The darkness puts fear in your soul, perhaps you should turn\n"
	+ "back and leave to see tomorrow. All around you lie the skulls\n"
	+ "of warriors who entered this cave and never left.\n";

items = ({
	"skulls", "White human skulls grinning and laughing at you",
});
    dest_dir =
        ({
        "players/pain/NEW/cave2", "in",
        "players/pain/NEW/tpath5", "out",
        });
if(!present("orc"))
{
move_object(clone_object("/players/pain/NEW/mon/orc_r"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_g"),this_object());
}
}

init() {
	::init();
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

