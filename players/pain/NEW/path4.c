

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Just South of the Hut.";
    no_castle_flag = 0;
    long_desc =
        "You stand before an aging hut with a thatched roof.\n"
        + "Through the window you see a young woman sitting in a chair.\n"
        + "The dirt path you are standing on narrows as it nears the\n"
        + "door of the hut. Grass struggles to grow along the sides of the\n"
        + "path, as the weeds have overrun the small area surrounding the\n"
        + "hut. A small garden grows to one side of the hut and a cow's pen\n"
        + "takes up the other side. It seems like a quaint little hut, yet\n"
        + "you feel as if something isn't right here.\n";

items = ({
	"hut", "A hut with a thatched roof. Perhaps you could enter it",
	"path", "A dirt path running through a forest",
	"woman", "A young women dressed all in black",
});
}

init() {
	::init();
        add_action("enter", "enter");
	add_action("south", "south");
}

enter(str) {
if(!str) {
	write("Enter what?\n");
	return 1;
}
if(str != "hut") {
	write("What would you like to enter?\n");
	return 1;
}
write("You see that the door is open and venture slowly into the hut.\n");
this_player()->move_player("slowly into the hut#players/pain/NEW/hut.c");
return 1;
}

south() {
if(present("quest1",this_player())) {
this_player()->move_player("south#players/pain/NEW/path3.c");
write("\nThere is a rustling in the trees to your left.\n");
write("A cloaked and hooded figure moves out from the trees.\n\n");
write("The figure says: So, you are helping Benedict's widow?\n\n");
write("The figure whispers to you: Just a word of advice, there are a few\n");
write("items that you will need to obtain in order to complete this quest.\n");
write("There are others that can give you more information, but I know that\n");
write("you will need the Plate Mail +1 from the Drow Captain in order to\n");
write("defeat the Blood Fisted Clan.\n\n");
write("The figure says: Good luck my friend, we are counting on you.\n");
return 1;
}
this_player()->move_player("south#players/pain/NEW/path3.c");
return 1;
}

query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}
realm() { return "NT"; }


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

