

inherit "room/room";

int searched;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The Throne Room";
    no_castle_flag = 0;
    long_desc = 
	  "This is the ancient throne room of the Blood Fisted Clan. Orcs\n"
	+ "mill all around hoping to gain the audience of the leader of the\n"
	+ "Clan, Cha'gr DeathBringer. A huge throne on a base of skulls is\n"
	+ "centered in the middle of the room, with guards and slaves all\n"
	+ "around it. The room is blatantly devoid of women, and grunts fill\n"
	+ "the air. The orcs eye you warily, but there is no fear in this\n"
	+ "room, save your's. If you have any hope of retaining your life\n"
	+ "you'd better not piss off the DeathBringer, as his mace is\n"
	+ "renowned throughout the world as a weapon of utter destruction.\n";

items = ({
	"skulls", "The skulls of those the DeathBringer has defeated.\n",
	"throne", "A huge golden throne with furs and silks as cushions.\n",
	"panel", "A suspicious looking panel in the wall, perhaps you should\n"
		 +"push it?\n",
	"slaves", "The down trodden slaves of the Clan.\n",
});
    dest_dir = 
        ({
        "players/pain/NEW/lair8", "west",
        });
if(!present("orc")) {
move_object(clone_object("/players/pain/NEW/mon/orc_w"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_w"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_m2"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_e"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_e"),this_object());
move_object(clone_object("/players/pain/NEW/mon/dbring"),this_object());
}
}

init() {
        add_action("search", "search");
	add_action("confuse","confuse");
	add_action("push", "push");
}

search(str) {
if(present("deathbringer")) {
	write("You begin to search around, but Deathbringer throws you"
	     +" across the room in a fit of rage.\n");
	searched = 0;
	return 1;
}
if(!str) {
	write("Search what?\n");
	searched = 0;
	return 1;
}
if(str == "here" || str == "room") {
	write("You begin to search the room in ernest.\n");
	write("After a little bit you see a panel in the wall that looks a\n"
	     +"little suspicious.\n");
	searched = 1;
	return 1;
}
else {
	write("You can't search that.\n");
	searched = 0;
	return 1;
}
}

push(str) {
if(!str) {
	write("What do you want to push?\n");
	return 1;
}
if(str != "panel") {
	write("You push "+str+" but nothing happens.\n");
	return 1;
}
if(present("deathbringer")) {
	write("You push on the panel, but before anything happens Deathbringer"
	     +" throws you across the room in rage.\n");
	return 1;
}
write("You push on the panel and a secret door slides open in the wall.\n");
searched = 0;
this_player()->move_player("into the hidden room#/players/pain/NEW/hidden");
return 1;
}


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
confuse() {
write("Deathbringer and the Orcs resist your confusion spell.\n");
this_player()->hit_player(20);
return 1;
}


