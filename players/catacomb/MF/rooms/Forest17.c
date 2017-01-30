inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
" The trees moan in agony from the lack of sunlight in the forest.\n"+
"Several have all but died already, but a few still stand fighting\n"+
"the overwhelming sadness of forest.  As the last branches of the \n"+
"dying trees fall, the ground almost seems to open up to devour the \n"+
"twig before it can gather any moss.\n");

items = ({
	"tree",
	"The few that are still alive battle to overcome the sadness",
	"trees",
	"The few that are still alive battle to overcome the sadness",
	"branches",
	"The ground devours it before it is able to gather any moss",
	"branch",
	"The ground devours it before it is able to gather any moss",
	"ground",
	"The ground almost seems to be alive consuming any branches that may fall"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest16.c","west",
	"/players/catacomb/MF/rooms/Forest18.c","east"
	});

}
