inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	
	short_desc=(HIW+"Duck Pond"+NORM);
	long_desc=
	""+GRN+"#####"+NORM+"R"+GRN+"##"+BBLU+HIB+"ww"+NORM+GRN+"##"+NORM+"|"+GRN+"##"+NORM+"     The path leads past a denser tree line here to the\n"+
	""+GRN+"##"+NORM+"|-----"+YEL+"B"+NORM+"-----"+GRN+"#"+NORM+"     west.  Puffy white clouds float overhead in the vast\n"+
	""+GRN+"##"+NORM+BOLD+"X"+NORM+"R"+BBLU+HIB+"www"+NORM+"R"+BBLU+HIB+"ww"+NORM+GRN+"#"+NORM+BOLD+"X"+NORM+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"     blue sky.  To the east a small shop is set up along\n"+
	""+GRN+"#"+NORM+"-|"+BBLU+HIB+"wwwwwww"+NORM+"R"+NORM+"|"+BBLU+HIB+"w"+NORM+"R"+GRN+"#"+NORM+"     the pond’s shore.\n"+
	""+BBLU+HIB+"wwwwwwwwwwwwww"+NORM+GRN+"#"+NORM+"\n";
	
	items = ({
			
			"   ","  ",
			
	});
	
	dest_dir = ({
			"/players/jareel/areas/duck_pond/road18.c","south",
                        "/players/jareel/areas/duck_pond/road2.c","north",			
			"/players/jareel/areas/duck_pond/shop.c","east",
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
