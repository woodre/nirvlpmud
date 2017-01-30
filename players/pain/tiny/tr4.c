inherit "room/room";
#include "/players/pain/color.h"


int widened;
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The "+RED+"Reading Room"+END;
    no_castle_flag = 0;
    long_desc = 
	"You have entered the Club's "+RED+"Reading Room"+END+".\n"+
	"The walls are lined from floor to ceiling with shelves that\n"+
	"contain some of the greatest literary works of all time. Each\n"+
	"shelf holds many leather bound books of varying size and color,\n"+
	"with gold lettering running down there bindings with the title.\n"+
	"Scattered about the room are many comfortable, overstuffed chairs\n"+
	"for club members, and their guests, to sit in while they read.\n"+
	"Behind one of the chairs you think you see a glimmer of\n"+
	"light shining up from some cracks in the floor.\n"+
	"By the door is a large stand with papers from across Nirvana with\n"+
	"all manner of news and information contained within them. This\n"+
	"like it would be a very comfortable place to sit and relax.\n";
	

items = ({
	"glimmer", "A small glimmer of light shining up from between "+
		"some cracks in the floor.\nPerhaps you could <widen> the <crack>?\nIt may provide a gateway to another world",
	"crack", "A crack in the floor that looks like you may be able "+
		"to widen it.",
	"books", "A huge assortment of leather bound books line the walls"+
		" about you.\n"+
		"You see titles that you can remember from your school days,"+
		" and some that\n"+
		"you've never seen before. It would take you hours to look"+
		" at them all",
	"shelves", "Rough hewn, handmade, wooden shelves holding many books",
	"stand", "An old fashioned newsstand containing the latest papers",
	"chairs", "Plush, overstuffed chairs, they look quite inviting",
	"papers", "The latest news papers from all around Nirvana",
	"lettering", "You see titles like 'the Inferno', 'the Illiad',"+
		" and 'A Tale of Two Cities'\n to name a few",
});
    dest_dir = 
        ({
	"/players/pain/tiny/tr3", "west",
        });
}

init() {
	::init();
add_action("listen","listen");
add_action("smell", "smell");
add_action("widen","widen");
add_action("enter","enter");
}

listen() {
write("It is quite quiet, you hear hardly a sound.\n");
return 1;
}

smell() {
write("You smell a slight musty scent from the aging books.\n");
return 1;
}

widen(str) {
if(!str || str != "crack") {
	write("What do you want to widen?\n");
	return 1;
}
if(widened) {
	write("The crack has already been widened.\n");
	return 1;
}
write("You bend down to examine the crack and see that if you punch it in\n"+
	"just the right place it'll open up more so you might be able\n"+
	"to crawl through it.\n\n"+
	"Concentrating you draw your fist back and smash it against the floor.\n"+
	"You smile as you see you were successful.\n\n"+
	"The crack has been widened. You think you could "+
	"<enter>\na new <realm>\n");
widened = 1;
return 1;
}

enter(str) {
if(!str || str != "realm") {
	write("What do you want to enter?\n");
	return 1;
}
if(this_player()->query_level() < 14) {
	write("I'm sorry young one, you are much to little to enter this realm.\n");
	widened = 0;
	return 1;
}
this_player()->move_player("into the crack#/players/snow/dark/rooms/r1");
widened = 1;
return 1;
}
query_light() {
    return 1;
}
