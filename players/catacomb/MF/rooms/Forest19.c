inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
"  The few trees that are here look very sickly.  The smell of \n"+
"a marsh pervades the area.  The ground becomes very soft to the\n"+
"south.  Nobody has ever tread into the dreaded marsh within the\n"+
"Meserir Forest.  Only those who are able to overcome their own\n"+
"fears have the slightest chance of surviving the dreaded marsh.\n");

items = ({
	"marsh",
	"The rumored home of Yeroc the nomad",
	"trees",
	"The trees wither and die before your eyes",
	"tree",
	"The trees wither and die before your eyes",
	"ground",
	"The ground becomes very soft making movement hard"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest15.c","northeast",
	"/players/catacomb/MF/rooms/Marsh2.c","marsh"
	});

}
