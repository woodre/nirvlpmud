/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";
inherit "room/room";

int searched;

reset(arg) {
    if (arg) return;

    set_light(1);
	short_desc = "A Twisting Path.";
    no_castle_flag = 0;
    long_desc =
        "You are standing at a small clearing along the path.\n"
        + "The trees stand tall above you shielding you from the sun\n"
        + "and providing a surreal setting. Further northwest you think\n"
        + "that you can make out a cave lying at the edge of the clearing.\n"
	+ "You think that you might be able to make out foot prints going\n"
	+ "to the northeast.\n";

items = ({
	"path", "A narrow dirt path running through the forest",
	"cave", "A cave nestled in amoungst the trees to the far northwest",
	"trees", "Tall trees line either side of the path",
	"foot prints", "There are some foot prints leading into the forest in"
	+ " a northeasterly\ndirection. You could probably 'search' for a way"
	+ " to follow them",
});
    dest_dir =
        ({
        "players/pain/NEW/tpath4", "northwest",
	"players/pain/NEW/tpath2", "south",
        });
    set_cost(660000);
    set_lot_size(9);
    set_realm_name("Bigelow");
    setup_land();
}

init() {
	::init();

add_action("search", "search");
add_action("northeast", "northeast");
}

search(str) {
 write("Pain is never going to finish this. So the druid grove is closed.\n");
 return 1;
if(!str) {
	write("Perhaps you should search for an exit?\n");
	searched = 0;
	return 1;
}
if(str != "for an exit") {
	write("Perhaps you want to 'search for an exit'?\n");
	searched = 0;
	return 1;
}
if(str == "for an exit") {
	write("You search the clearing for a hidden exit.\n");
	write("After a few minutes of searching you find an exit"
	      +" to the northeast!\n");
	searched = 1;
	return 1;
}
}

northeast() {
if(searched != 1) {
	write("You can't go that way!\n");
   write("Perhaps you should search to be sure there's an exit first.\n");
	return 1;
}
if(searched == 1) {
	this_player()->move_player("deeper into the forest#players/eurale/Druid/df1.c");
	searched = 0;
	return 1;
}
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

