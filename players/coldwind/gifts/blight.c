#include "/players/coldwind/define.h"

#define user this_player()->query_name()
inherit "obj/treasure.c";

id(str){ return str == "magical sphere" || str == "sphere"; }
short(){ return ""+HIM+"Magical Sphere"+NORM+""; }
query_weight(){ return 10000; }     


long()

{
	write("  A small magical ball glowing slightly and flloating\n"+
		  "freely in your room. It seems smart enough to obey your\n"+
		  "orders, you snap and the ball will emite light, or you\n"+
		  "can clap and it will stop creating light.\n");
}

init()
{
	add_action("giftt", "snap");
	add_action("stop", "clap");
}

giftt(){

set_light(4);
say("You hear a S N A P!!\n"+
		 "The magical ball's glow increases...\n");
write("You snap your fingers.\n"+
	  "The magical ball's glow increases.\n");
	return 1;
}

stop(){

set_light(0);
say(""+user+" claps "+tp->POS +" hand once.\n"+
	"The magical ball's glow dims till the room goes dark.\n");
write("You clap your hands one and the room goes dark. \n");
	return 1;
}

