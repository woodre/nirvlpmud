

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A Twisting Path";
    no_castle_flag = 0;
    long_desc =
          "The path continues north towards a strange realm.\n"
        + "You are just north of a small clearing containing a cave.\n"
        + "The trees tower over you and the mountains loom over the forest\n"
        + "to the west. All about you is nature.\n";

items = ({
	"path", "A narrow, muddy path through the forest",
});
    dest_dir =
        ({
        "players/pain/NEW/tpath7", "north",
        "players/pain/NEW/tpath5", "south",
        });
if(!present("orc"))
{
move_object(clone_object("/players/pain/NEW/mon/orc_r"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_r"),this_object());
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

