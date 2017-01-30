inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	
	short_desc=(HIW+"Duck Pond"+NORM);
	long_desc=
	""+GRN+"#####"+NORM+"R"+GRN+"##"+BBLU+HIB+"ww"+NORM+GRN+"##"+NORM+"|"+GRN+"##"+NORM+"     This is the Duck Pond dock, were adventurers can\n"+
	""+GRN+"##"+NORM+"|-----"+YEL+"B"+NORM+"-----"+GRN+"#"+NORM+"     launch boats into the pond.  The Duck Pond trader\n"+
	""+GRN+"##"+NORM+"|R"+BBLU+HIB+"www"+NORM+"R"+BBLU+HIB+"ww"+NORM+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"     sets up his small beat up shop to the west.  Tall\n"+
	""+GRN+"#"+NORM+"-|"+NORM+BBLU+HIB+"wwwwwww"+NORM+"R"+NORM+BOLD+"X"+NORM+BBLU+HIB+"w"+NORM+"R"+GRN+"#"+NORM+"     white puffy clouds float overhead in the open blue\n"+
	""+BBLU+HIB+"wwwwwwwwwwwwww"+NORM+GRN+"#"+NORM+"     sky.\n";
	
	items = ({
			
			"   ","  ",
			
	});
	
	dest_dir = ({
			"/players/jareel/areas/duck_pond/road14.c","north",
                        "/players/jareel/areas/duck_pond/trader.c","west",			
			
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
