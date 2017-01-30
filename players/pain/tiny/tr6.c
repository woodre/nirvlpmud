inherit "room/room";
#include "/players/pain/color.h"

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The "+RED+"Club's Office"+END;
    no_castle_flag = 0;
    long_desc = 
	"You have entered the Club's "+RED+"Office"+END+".\n"+
	

items = ({
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
}

listen() {
write("It is quite quiet, you hear hardly a sound.\n");
return 1;
}

smell() {
write("You smell a slight musty scent from the aging books.\n");
return 1;
}

query_light() {
    return 1;
}
