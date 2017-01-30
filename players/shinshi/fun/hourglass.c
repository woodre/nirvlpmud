inherit "/obj/treasure.c";
int charges;
#include <ansi.h>

reset(arg)
{
  SetMultipleIds(({"hourglass", "shinshi_hourglass"}));
  charges = 3;
  short_desc = HIK+"The Hourglass of Time"+NORM;
  long_desc = "The hourglass gleams into the light as the sands inside lay rested\n"+
  "at the bottom of the hourglass. A tiny clock, located on the bottom, counts\n"+
  "down the time as normal. There's a small inscription on the top that you might\n"+
  "be able to read.\n";
}  

get() {
	if(!present("dervish_tattoo", this_player())) {
		write("The sands prevent the hourglass from going to a non-Dervish.\n");
		return 0;
	}
	return 1;
}

query_weight() { return charges; }
query_value(){ return 0; }


init()
{
	::init();
	
	add_action("turn", "turn");
	add_action("read", "read");
}

turn(str){
	object go_go;
	
	if(!str){
		write("Turn what?\n");
		return 1;
	}
	
	if(str != "hourglass"){
		write("That isn't here to turn.\n");
		return 1;
	}
	
	if(present("go_go", this_player())){
		write("The hourglass is already speeding up time.\n");
		return 1;
	}
	
	if(!present("dervish_tattoo", this_player())){
		write("You cannot use this!\n");
		return 1;
	}
	
	if(str == "hourglass")
        {
		go_go = clone_object("/players/shinshi/fun/go_go.c");
		move_object(go_go, this_player());
		go_go->start_it();
		charges--;
		write("As the hourglass turns, the "+HIY+"S"+NORM+YEL+"an"+NORM+HIY+"ds"+NORM+" begin\n"+
		"to flow from the top of the hourglass to the\n"+
		"top to the bottom. The tiny clock on the bottom\n"+
		"begins to spin wildly out of control.\n");
		if(charges <= 0){
			write("The hourglass glows brightly and explodes in thousands of glass shards.\n");
			destruct(this_object());
			}
		return 1;
	}
	return 1;
}

read(str){
	if(present("dervish_tattoo", this_player())){
		if(!str){
			write("What would you like to read?\n");
			return 1;
		}
	
		if(str != "inscription"){
			write("Perhaps you should read the inscription.\n");
			return 1;
		}
	
		if(str == "inscription"){
			write("\n        The Hourglass of Time can speed up the Sands around you\n"+
			"        and temporarily give you the power to regain your spell delay\n"+
			"        quicker. You can probably 'turn' it. It has "+charges+" left.\n");
			return 1;
		}
	}
}

locker_arg(){ return ""+charges; }
locker_init(arg){ charges = atoi(arg); }
restore_thing(str){ restore_object(str); return 1; }
save_thing(str){ save_object(str); return 1; }
generic_object(){ return 1; }
