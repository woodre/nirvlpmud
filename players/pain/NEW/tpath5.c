

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
	short_desc = "A Twisting Path.";
    no_castle_flag = 0;
    long_desc =
        "You are standing in the middle of a clearing in the forest.\n"
        + "The trees stand tall above you shielding you from the sun\n"
        + "and providing a surreal setting. To the north the path leads\n"
        + "towards an unknown realm.\n"
        + "A large cave is nestled on the fringe of the clearing.\n";

items = ({
	"path", "A narrow dirt path running through the forest",
	"cave", "A cave nestled in amoungst the trees with a gaping entrance",
	"trees", "Tall trees line either side of the path",
});
    dest_dir =
        ({
        "players/pain/NEW/tpath6", "north",
	"players/pain/NEW/tpath4", "south",
        });
if(!present("footman"))
{
move_object(clone_object("/players/pain/NEW/mon/footman"),this_object());
move_object(clone_object("/players/pain/NEW/mon/footman"),this_object());
}
if(!present("merchant"))
{
move_object(clone_object("/players/pain/NEW/mon/merchant"),this_object());
move_object(clone_object("/players/pain/NEW/mon/merchant"),this_object());
}
}

init() {
	::init();

add_action("enter", "enter");
}

enter(str) {
if(!str) {
	write("What exactly are you going to enter?\n");
	return 1;
}
if(str != "cave") {
	write("That is not here.\n");
	return 1;
}
this_player()->move_player("into the dark cave#players/pain/NEW/cave1.c");
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

