inherit "room/room";
#include "/players/pain/color.h"

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The "+RED+"Coatroom"+END;
    no_castle_flag = 0;
    long_desc = 
	"You have entered the Club's "+RED+"Coatroom"+END+".\n"+
	"You are surrounded by all manners of coats here, they\n"+
	"line the walls, all hanging neatly on polished wooden\n"+
	"hangers. There are a few wool top coats, some minks, a\n"+
	"fox or two and there's even a beaver fur hat. Overall,\n"+
	"there's some nice stuff here. There is a sign clearly\n"+
	"posted on each wall.\n";
	

items = ({
	"sign", "A large sign with the simple, yet worn out phrase:\n"+
		GREEN+"Not Responsible for Lost or Stolen Items"+END+".\n"+
		"\t\t-the Management",
	"coats", "An assortment of furs, wool top coats, and the occasional\n"+
		"simple rain coat",
	"top coat", "A handsome, hand-stitched wool top coat",
	"wool top coat", "A handsome, hand-stitched wool top coat",
	"fur coat", "A beautiful, plush, soft fur coat",
	"mink coat", "A beautiful mink coat, it smells of old lady",
	"fox coat", "A handsome coat made of rare fox fur",
	"wool top coats", "An assortment of well tailored wool top coats",
	"top coats", "An assortment of well tailored wool top coats",
	"fur coats", "An assortment of beautiful fur coats",
	"hat", "A hand made beaver fur hat, like you see in the movies",
	"beaver hat", "A hand made beaver fur hat, like you see in the movies",
	"fur hat", "A hand made beaver fur hat, like you see in the movies",
});
    dest_dir = 
        ({
	"/players/pain/tiny/entrance", "east",
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
write("You smell old furs, damp wool and moth balls.\n");
return 1;
}

query_light() {
    return 1;
}
