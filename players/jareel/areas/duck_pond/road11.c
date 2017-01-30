inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	
	short_desc=(HIW+"Duck Pond"+NORM);
	long_desc=
	""+GRN+"#####"+NORM+"R"+GRN+"##"+BBLU+HIB+"ww"+NORM+GRN+"##"+NORM+"|"+GRN+"##"+NORM+"     Cobblestones are meticulously placed covering the\n"+
	""+GRN+"##"+NORM+"|-----"+YEL+"B"+NORM+"---"+BOLD+"X"+NORM+"-"+GRN+"#"+NORM+"     path, traveling through Duck Pond.  The path leads\n"+
	""+GRN+"##"+NORM+"|R"+BBLU+HIB+"www"+NORM+"R"+BBLU+HIB+"ww"+NORM+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"     to the north, east and west here. The pond can be\n"+
	""+GRN+"#"+NORM+"-|"+BBLU+HIB+"wwwwwww"+NORM+"R"+NORM+"|"+BBLU+HIB+"w"+NORM+"R"+GRN+"#"+NORM+"     seen past a few trees to the south.\n"+
	""+BBLU+HIB+"wwwwwwwwwwwwww"+NORM+GRN+"#"+NORM+"\n";
	
	items = ({
			
			"   ","  ",
			
	});
	
	dest_dir = ({
			"/players/jareel/areas/duck_pond/road1.c","north",
                        "/players/jareel/areas/duck_pond/road10.c","west",
                        "/players/jareel/areas/duck_pond/road12.c","east",
			
			
	});
	
}
init() {
	::init();
	add_action("Search","search");
}

Search(str) {
	
	if(!str) { write("Search what?\n"); return 1; }
	write("You search the "+str+" but find nothing special.\n");
	say(this_player()->query_name()+" searches around for something.\n");
	return 1;
}
