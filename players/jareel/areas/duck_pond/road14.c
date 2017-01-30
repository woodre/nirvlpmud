inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	
	short_desc=(HIW+"Duck Pond"+NORM);
	long_desc=
	""+GRN+"#####"+NORM+"R"+GRN+"##"+BBLU+HIB+"ww"+NORM+GRN+"##"+NORM+"|"+GRN+"##"+NORM+"     Flashing sparkles of reflecting light jump off the\n"+
	""+GRN+"##"+NORM+"|---"+BOLD+"X"+NORM+"-"+YEL+"B"+NORM+"-----"+GRN+"#"+NORM+"     rippling pond.  The cobblestone path is darker here\n"+
	""+GRN+"##"+NORM+"|R"+BBLU+HIB+"www"+NORM+"R"+BBLU+HIB+"ww"+NORM+GRN+"#"+NORM+BOLD+"X"+NORM+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"     with a moisture covering the rocks.  Big, tall puffy\n"+
	""+GRN+"#"+NORM+"-|"+BBLU+HIB+"wwwwwww"+NORM+"R"+NORM+"|"+BBLU+HIB+"w"+NORM+"R"+GRN+"#"+NORM+"     clouds float overhead in the crystal clear sky.\n"+
	""+BBLU+HIB+"wwwwwwwwwwwwww"+NORM+GRN+"#"+NORM+"\n";
	
	items = ({
			
			"   ","  ",
			
	});
	
	dest_dir = ({
			"/players/jareel/areas/duck_pond/road17.c","south",
                        "/players/jareel/areas/duck_pond/road10.c","north",			
			
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
