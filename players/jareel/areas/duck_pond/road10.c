inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	
	short_desc=(HIW+"Duck Pond"+NORM);
	long_desc=
	""+GRN+"#####"+NORM+"R"+GRN+"##"+BBLU+HIB+"ww"+NORM+GRN+"##"+NORM+"|"+GRN+"##"+NORM+"     Cobblestones are meticulously placed over the road\n"+
	""+GRN+"##"+NORM+"|-----"+YEL+"B"+NORM+"--"+BOLD+"X"+NORM+"--"+GRN+"#"+NORM+"     running through Duck Pond.  Clouds float past the\n"+
	""+GRN+"##"+NORM+"|R"+BBLU+HIB+"www"+NORM+"R"+BBLU+HIB+"ww"+NORM+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"     shining sun overhead, casting a dull shadow over the\n"+
	""+GRN+"#"+NORM+"-|"+BBLU+HIB+"wwwwwww"+NORM+"R"+NORM+"|"+BBLU+HIB+"w"+NORM+"R"+GRN+"#"+NORM+"     path, and surrounding trees.  The path leads to the\n"+
	""+BBLU+HIB+"wwwwwwwwwwwwww"+NORM+GRN+"#"+NORM+"     south, east and west here.\n";
	
	items = ({
			
			"   ","  ",
			
	});
	
	dest_dir = ({
			"/players/jareel/areas/duck_pond/road14.c","south",
                        "/players/jareel/areas/duck_pond/road9.c","west",
                        "/players/jareel/areas/duck_pond/road11.c","east",			
			
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
