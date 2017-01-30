inherit "room/room";
#include "/players/pain/color.h"

int is_opened;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The "+RED+"Cigar"+END+" Room";
    no_castle_flag = 0;
    long_desc = 
        "You have entered the "+RED+"Cigar Room"+END+" of the Club.\n"+
	"There are three leather couches in the room, a dark burgundy\n"+
	"one dominates the center of the far wall, with a hunter green\n"+
	"couch flanking it on either side. In each corner stands a\n"+
	"handmade humidor full of cigars. You can tell that these cigars\n"+
	"are the good ones, you think you can even spot a few boxes of\n"+
	"Cubans. There is an exhaust fan on each wall to help with the\n"+
	"ventilation, and some floor lamps scattered about the place to\n"+
	"provide a soft glow to the room.\n"+
	"There is a small booth in the corner with a door.\n"+
	"You see an odd leaf lying on the floor.\n";
	

items = ({
	"booth", "This looks like some sort of teleport booth, perhaps you could enter it",
	"door", "You could most likely open the door to enter the teleport booth",
	"leaf", "An odd looking leaf. You get the strange feeling that you'd be\n"+
		"transported somewhere if you \"sniff\"ed it",
	"humidor", "This is one of four humidors in the room.\n"+
		"It stands about 8 feet tall, almost reaching the ceiling,\n"+
		"and has six shelves, each holding approximately five\n"+
		"smaller humidors containing some of the best cigars in the\n"+
		"world. It would seem that all the cigars in this humidor\n"+
		"are of the 'Churchhill' variety. They are all around\n"+
		"seven and a half inches long and fifty-five millimeters in\n"+
		"circumference. They look absolutely delicious",
	"humidor 2", "This is one of four humidors in the room.\n"+
                "It stands about 8 feet tall, almost reaching the ceiling,\n"+
                "and has six shelves, each holding approximately five\n"+
                "smaller humidors containing some of the best cigars in the\n"+
                "world. It appears that all the cigars in this humidor are\n"+
		"of the 'Rothschild' variety. They are all approximately\n"+
		"five and a half inches long and forty-five millimeters in\n"+
		"diameter. They look like they'd be a nice, smooth cigar.\n",
	"humidor 3", "This is one of four humidors in the room\n"+
                "It stands about 8 feet tall, almost reaching the ceiling,\n"+
                "and has six shelves, each holding approximately five\n"+
                "smaller humidors containing some of the best cigars in the\n"+
                "world. The cigars in this humidor are all categorized in\n"+
		"the 'Presidente' variety. They are all over eight inches\n"+
		"long, and are all at least fifty millimeters around. These\n"+
		"are the largest kind of cigar, it'd probably take an hour\n"+
		"at least to smoke them",
	"humidor 4", "This is one of four humidors in the room.\n"+
                "It stands about 8 feet tall, almost reaching the ceiling,\n"+
                "and has six shelves, each holding approximately five\n"+
                "smaller humidors containing some of the best cigars in the\n"+
                "world. The cigars in this humidor look like they are all\n"+
		"the 'Torpedo' variety. They are rather short, about five\n"+
		"inches in length, and are pretty fat, fifty millimeters\n"+
		"around and up. They look like a pretty rough smoke",
	"couches", "There are three leather couches set up in the room for\n"+
		"the enjoyment of the smokers. They look quite comfortable,\n"+
		"overstuffed and very cushy, with no annoying throw pillows\n"+
		"to get in your way",
	"burgundy couch", "This burgundy couch takes up a large portion of\n"+
		"the far wall. It look quite plush, and smells of leather,\n"+
		"cognac and cigars, a not all together unpleasing smell",
	"green couch", "On either side and perpendicular to the burgundy\n"+
		"couch is a dark, hunter green, leather couch. They are\n"+
		"well worn, but are still very handsome",
	"fan", "A small exhaust fan to provide ventilation for the smokers.\n",
	"exhaust fan", "A small fan built into the wall to provide ventilation"+
		" for the smokers",
	"lamp", "A brass floor lamp with a green lampshade. It provides a\n"+
		"soft sheen of light, yet looks quite masculine",
});
    dest_dir = 
        ({
	"/players/pain/tiny/entrance", "west",
        });
}

init() {
	::init();
	add_action("listen","listen");
	add_action("smell", "smell");
	add_action("sniff","sniff");
	add_action("open","open");
	add_action("enter","enter");
}


open(str) {
if(!str || str != "door") {
	write("Open what??\n");
	return 1;
}
if(str == "door") {
	write("You open the door to the teleport booth.\n");
	is_opened = 1;
	return 1;
}
}

enter(str) {
if(!str || str != "booth") {
	write("Perhaps you'd like to 'enter' the 'booth'?\n");
	return 1;
}
if(!is_opened) {
	write("You should most likely open the door first.\n");
	return 1;
}
this_player()->move_player("into the booth#/players/eurale/Space/teleport_up");
is_opened = 0;
return 1;
}

listen() {
write("You hear the hushed sounds of mellow conversation and smoking.\n");
return 1;
}

smell() {
write("You smell the heady smoke of cigars and the sweetness of cognac.\n");
return 1;
}

sniff(str) {
if(!str || str != "leaf") { return 0; }
else {
	write("You sniff the leaf and an odd sensation comes over you.\n");
	this_player()->move_player("through space and time#/players/balowski/tiny/a2");
	return 1;
}
}

query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}

