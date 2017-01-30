/*  Added the ability to 'haggle'.  What this does is takes the players
intelligence vs. the intelligence of the shopkeeper, randomizes them
both, and if the player scores higher can get the item for cheaper.
If lower, will get the item for higher. Normal purchasing is still
available. */

#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object item;
int cost, haggle, owner_int;
string what;
object owner;
reset(arg) {
	if(!present("clerk_owner")){
		owner = clone_object("/players/maledicta/town/mobs/heal_owner.c");
		move_object(owner, this_object());
	}
	/* Replacing average 10 intelligence with average 20 -Snow 3/00
	owner_int = random(21);
	if(owner_int < 10) owner_int = 10;
	*/
	owner_int = random(20)+10;
	
	if(arg) return;
	set_light(1);
	
	short_desc = ""+HIG+"Derellia IV"+NORM+"[medical shop]";
	long_desc =
	"  This is the medical shop of Derellia IV. Several aisles of medical\n"+
	"equipment and tools can be found throughout the store. The walls are\n"+
	"covered with shelves containing more medical supplies. A counter is\n"+
	"near the entrance, a small register sitting on it.  You feel that it\n"+
	"would be alright to 'browse' the store. A display next to the counter\n"+
	"allows you to 'view' information on the supplies.\n";
	
	items = ({
			"aisles",
			"long aisles of shelves and racks containing medical supplies",
			"shelves",
			"Metal shelving used to hold medical supplies",
			"racks",
			"Wood and metal racks used to hold medical supplies",
			"display",
			"A shiney chrome display with a digital readout. You can 'view' it\n"+
			"to see information on the stores supplies",
			"equipment",
			"Instruments of healing meant for the travelers who visit and the\n"+
			"population of the town",
			"tools",
			"Tools of healing meant for the travelers who visit and the population\n"+
			"of the town",
			"walls",
			"The walls are made of white stone and are covered with shelves",
			"supplies",
			"Medical supplies used for healing and the care of the town",
			"counter",
			"A small wood counter used for transactions",
			"entrance",
			"A wooden door with glass that leads out into the street",
			"register",
			"A small computer register used for transactions",
	});
	
	dest_dir = ({
			"/players/maledicta/town/rooms/t8.c","out",
	});
	
}

init(){
	::init();
	add_action("browse_it", "browse");
	add_action("purchase_it","purchase");
	add_action("haggle_it", "haggle");
	add_action("info_it", "view");
	add_action("backroom", "backroom");
	this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }


backroom(){
	if(!present("drug_dealer", this_player())) return;
	move_object(this_player(), "/players/maledicta/town/rooms/backroom.c");
	command("look", this_player());
	write("You arrive at the backroom of the medical shop.\n");
	return 1;
}



info_it(str){
	if(!str){
		write("View what?\n");
		return 1;
	}
	if(str == "display"){
		write(
			"The display reads:\n"+
			"1.  FirstAid kit(9): A 9 dose heal that has low tox/low healing. Made\n"+
			"                     generally for newbies.\n"+
			"2.  Medical kit(3):  A 3 dose heal that heals for hps only. Low tox.\n"+
			"3.  Bloodcleanser(single shot): Detoxer, intox only.\n"+
			"4.  Bloodcleanser(large shot): Multi-use detoxer. intox only.\n"+
			"5.  Rejuvenation Patch(3): Same as Medical Kit, only sps only.\n"+
			"6.  Injector GREEN (3): heals hps & sps. Very high tox.\n"+
		"7.  Blue gel (3): heals sps only. Very high tox.\n"+
       "8.  Injector YELLOW (3): a lower dosage hps & sps. Very high tox.\n");
		return 1;
	}
	write("View what?\n");
	return 1;
}

browse_it(){
	write(
		"          "+HIR+"----============"+NORM+"["+HIR+"Medical Shop"+NORM+"]"+HIR+"============----\n"+
		"          -                                            -\n"+
		"          -__"+NORM+"Items"+HIR+"____________________________"+NORM+"Cost"+HIR+"_____-\n"+
		"          -  	                                       -\n"+
		"          -"+NORM+" 1. FirstAid kit"+NORM+"(9)....................1200 "+HIR+"-\n"+
                "          -"+NORM+" 2. Medical kit"+NORM+"(3).....................2600 "+HIR+"-\n"+
		"          -"+NORM+" 3. "+HIR+"Blood"+NORM+"cleanser"+NORM+"(single shot)..........300 "+HIR+"-\n"+
		"          -"+NORM+" 4. "+HIR+"Blood"+NORM+"cleanser"+NORM+"(large shot)...........900 "+HIR+"-\n"+
		"          -"+NORM+" 5. "+HIG+"Rejuvenation Patch"+NORM+"(3)..............1950 "+HIR+"-\n"+
		/* "          -"+NORM+" 6. Injector "+HIB+"BLUE"+NORM+"(15).................10000 "+HIR+"-\n"+ */
		"          -"+NORM+" 6. Injector "+HIG+"GREEN"+NORM+"(3)..................1200 "+HIR+"-\n"+
		"          -"+NORM+" 7. "+BLU+"Blue Gel"+NORM+"(3).........................800 "+HIR+"-\n"+
       "          -"+NORM+" 8. Injector "+YEL+"YELLOW"+NORM+" (3).................720 "+HIR+"-\n"+
		"          -                                            -\n"+
		"          ----================"+NORM+"["+HIR+"-+-"+NORM+"]"+HIR+"=================----"+NORM+"\n"+
	"          You may purchase # or haggle # over the price.   \n");
	return 1;
}


purchase_it(string str){
	if(!present("clerk_owner", this_object())){
		write("You don't see the clerk here.\n");
		return 1;
	}
	if(!str){ write("Usage: purchase 1-6.\n"); return 1; }
	if(str == "1"){
		cost = 1200;
		item = clone_object("/players/maledicta/town/obj/fkit.c");
		what = "first-aid kit";
	}
	else if(str == "2"){
                cost = 2600;
		item = clone_object("/players/maledicta/town/obj/kit.c");
		what = "medical kit";
	}
	else if(str == "3"){
		cost = 300;
		item = clone_object("/players/maledicta/town/obj/shot_small.c");
		what = "shot";
	}
	else if(str == "4"){
		cost = 900;
		item = clone_object("/players/maledicta/town/obj/shot_large.c");
		what = "shot";
	}
	else if(str == "5"){
		cost = 1950;
		item = clone_object("/players/maledicta/town/obj/patch.c");
		what = "patch";
	}
	else if(str == "6"){
		cost = 1200;
		item = clone_object("/players/maledicta/town/obj/green.c");
		what = "injector";
	}
	else if(str == "7"){
		cost = 800;
		item = clone_object("/players/maledicta/town/obj/gel.c");
		what = "gel";
	}
	else if(str == "8"){
       cost = 720;
       item = clone_object("/players/maledicta/town/obj/yellow.c");
       what = "injector";
   }
	else{
		write("The clerk says: I'm sorry, we don't carry that.\n");
		return 1;
	}
	
	if (call_other(this_player(), "query_money", 0) < cost) {
		write("Clerk says: I'm sorry, but you don't have enough coins for that.\n");
		return 1;
	}
	if(!this_player()->add_weight(item->query_weight())) {
		write("The clerk says: It doesn't look like you can carry that.\n");
		destruct(item);
	return 1; }
	write("The clerk thanks you as you pay "+cost+" coins for a "+what+".\n");
	say(tp->query_name() + " purchases a "+what+".\n");
	move_object(item,this_player());
	tp->add_money(-cost);
	return 1;
}


haggle_it(string str){
	if(!present("clerk_owner", this_object())){
		write("You don't see the clerk here.\n");
		return 1;
	}
	if(!str){ write("Usage: haggle 1-6.\n"); return 1; }
	if(str == "1"){
		cost = 1200;
		haggle = 400;
		item = clone_object("/players/maledicta/town/obj/fkit.c");
		what = "first-aid kit";
	}
	else if(str == "2"){
                cost = 2600;
		haggle = 450;
		item = clone_object("/players/maledicta/town/obj/kit.c");
		what = "medical kit";
	}
	else if(str == "3"){
		cost = 300;
		haggle = 60;
		item = clone_object("/players/maledicta/town/obj/shot_small.c");
		what = "shot";
	}
	else if(str == "4"){
		cost = 900;
		haggle = 150;
		item = clone_object("/players/maledicta/town/obj/shot_large.c");
		what = "shot";
	}
	else if(str == "5"){
		cost = 1950;
		haggle = 500;
		item = clone_object("/players/maledicta/town/obj/patch.c");
		what = "patch";
	}
	else if(str == "6"){
		cost = 1200;
		haggle = 300;
		item = clone_object("/players/maledicta/town/obj/green.c");
		what = "injector";
	}
	else if(str == "7"){
		cost = 800;
		haggle = 200;
		item = clone_object("/players/maledicta/town/obj/gel.c");
		what = "gel";
	}
	else if(str == "8"){
       cost = 720;
       haggle = 200;
       item = clone_object("/players/maledicta/town/obj/yellow.c");
       what = "injector";
   }
	else{
		write("The clerk says: I'm sorry, we don't carry that.\n");
		return 1;
	}
	if (call_other(this_player(), "query_money", 0) < (cost + haggle)) {
		write("Clerk says: I'm sorry, but you don't have enough coins for that.\n");
		return 1;
	}
	
	if(random(this_player()->query_attrib("int"))  > random(owner_int)){
		write(
		"Clerk says: Ok, but I am just giving it away at that price!\n");
		cost -= random(haggle);
	}
	else{
		write(
		"Clerk says: Yeah, It is actually worth more, sorry about that.\n");
		if(haggle < 1) haggle = 10;
		cost += random(haggle);
	}
	
	if(!this_player()->add_weight(item->query_weight())) {
		write("The clerk says: It doesn't look like you can carry that.\n");
		destruct(item);
	return 1; }
	write("The clerk thanks you as you pay "+cost+" coins for a "+what+".\n");
	say(tp->query_name() + " purchases a "+what+".\n");
	move_object(item,this_player());
	tp->add_money(-cost);
	return 1;
}

