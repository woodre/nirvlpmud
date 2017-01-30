#define NAME "Pain"
#define DEST "room/exlv_guild"

id(str) { return str == "castle" || str == "door"; }

short() {
return "A glowing door with the words \"Wizard's Club\" over it";
}

long() {
write("Perhaps you could open the door.\n");
}
init() {
    add_action("open"); add_verb("open");
}
open(str) {
if(str != "door") {
	write("What do you want to open?\n");
	return 1;
}
this_player()->move_player("into the \"Wizard's Club\"#players/pain/tiny/entrance");
return 1;
}
reset(arg) {

    if (arg)
	return;
    move_object(this_object(), DEST);

}
is_castle(){return 1;}
