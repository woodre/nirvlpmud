inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("hoji")) {
	move_object(clone_object("/players/shinshi/weapon/mob/hoji.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = "Fix This Later";
	long_desc =
		"Fix\n"+
		"This\n"+
		"Later\n"+
		"God\n"+
		"DAMMIT\n";


items =

({
	"doors", "Which doors? Wooden or glass?",
	"glass doors", "Large glass doors make an exit to the outside",
	"walls", "Bare walls surround you",
	"floor", "The floor glistens and sparkles",
	"light", "Large lights are lined evenly among the ceiling",
	"ceiling", "White rectangular tiles form a ceiling",
	"plant", "A small plant that seems too green to be real",
	"corner", "Where two walls come together",
	"lighting", "Large lights are lined evenly along the ceiling",
});

/*dest_dir =
({
	"/players/shinshi/areas/coining/rooms/rm2.c", "north",
	"/players/shinshi/entrancehall.c", "exit",
});*/
}

init(){
  ::init();
	add_action("make", "make");
  }
  
make(str){
	int money, goal, total, balance;
	string where;

	
	if(!str){
		write("Usage: make payment <money> <cash/bank>\n");
		return 1;
	}
	
	sscanf(str, "payment %s %s", money, where);
	write("You attempted to make a payment of "+money+" from "+where+".\n");                      /*for debugging purposes*/
	return 1;
	
	goal = 500000;
}
	
/*	if(where == "cash"){
		if(!money){
			write("You don't have enough money!\n");
			return 1;
		}
	
		if(money > this_player()->query_money()){
			write("You don't have that much on you!\n");
			return 1;
		}
		
		if(money <= this_player()->query_money()){
			if(
*/