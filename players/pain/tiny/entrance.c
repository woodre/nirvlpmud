inherit "room/room";
#include "/players/pain/color.h"

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The Entrance to the "+BLUE+"Wizards' Club"+END;
    no_castle_flag = 0;
    long_desc = 
        "You have reached the entrance to the "+BLUE+
	"Wizards' Club"+END+"\n"+
	"This club is linked to several small areas all made by different\n"+
	"wizards. As you gaze around the room you see that this is a rather\n"+
	"exclusive club, providing the finest amenities for Nirvana's best\n"+
	"and brightest. The walls are covered with brilliant cherry wood.\n"+
	"Pictures of the club's members adorn the wall, making you feel\n"+
	"a little uncomfortable standing amongst the greatness. The clubs'\n"+
	"crest adorns the archway over the entrance. You think that this\n"+
	"would be an excellent place to adventure.\n"+
	"A "+RED+"Members' List"+END+" is framed here on the wall.\n";
	

items = ({
	"list", "A large sign with the list of "+RED+"Members"+
		END+" to the club on it:\n"+
		"\t\tBalowski,\n"+
		"\t\tPain,\n"+
		"\t\tEurale,\n"+
		"\t\tSnow,\n"+
		"\t\tAnshar,\n"+
		"\t\tPavlik",
	"crest", "A beautiful crest with a laurel surrounding a wand with a"+
		" crown atop it.\n"+
		"You can see the motto enscribed beneath it, '"+BLUE+
		"Excellence"+END+",\n"+
		GREEN+"Creativity"+END+" and "+PURPLE+"Unity'"+END,
	"pictures", "Handsome framed pictures of the founders of the club.\n",
});
    dest_dir = 
        ({
	"/players/pain/tiny/tr1", "east",
	"/players/pain/tiny/tr2", "west",
	"/players/pain/tiny/tr3", "north",
	"/room/exlv_guild", "out",
        });
}

init() {
	::init();
add_action("listen","listen");
add_action("smell", "smell");
}

listen() {
write("You hear the low hum of meandering members of high-society.\n");
return 1;
}

smell() {
write("You smell old money and liquer.\n");
return 1;
}

query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}

