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

object owner;
string what;
int cost, haggle, owner_int;
object item;


reset(arg) {
	if(!present("store_owner")){
		owner = clone_object("/players/maledicta/town/mobs/armor_owner.c");
		move_object(owner, this_object());
	}
	
	owner_int = random(21);
	if(owner_int < 10) owner_int = 10;
	
	if(arg) return;
	set_light(1);
	
	short_desc = ""+HIG+"Derellia IV "+NORM+"[armorer]";
	long_desc =
	"   You have entered an armory shop. Standing along the stone walls are\n"+
	"several shelves and racks, each covered with pieces of armor. Ahead\n"+
	"near the rear of the store is a small counter with a cash register\n"+
	"on it. You feel that it would be ok to 'browse' the merchandise.\n";
	
	items = ({
			"walls",
			"White stone walls that are covered with shelves and racks",
			"shelves",
			"Made of steel and wood, they are covered with pieces of armor",
			"racks",
			"Made of steel, each carry the heavier pieces of armor that is\n"+
			"available",
			"counter",
			"A small wood counter with a glass case in its center",
			"register",
			"A small computer register for transactions",
			
			
	});
	
	dest_dir = ({
			"/players/maledicta/town/rooms/t12.c","out",
	});
	
}

init(){
	::init();
	add_action("browse_it", "browse");
	add_action("purchase_it","purchase");
	add_action("haggle_it", "haggle");
	add_action("fix_armor", "fix");

	this_player()->set_fight_area();
}

backroom(){
if(!present("clan_symbio", this_player())) return;
move_object(this_player(), "/players/maledicta/town/rooms/backroom2");
tell_object(this_player(), "You enter the backroom.\n");
command("look", this_player());
return 1;
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }


browse_it(){
	write(
		"    You browse the store's selection....\n\n"+
		"     ________________________________________________________  \n"+
		"     *************    "+HIY+"The Traveler's Shield"+NORM+"    **************  \n"+
		"     ________________________________________________________  \n"+
		"        Item:                                     Cost:	  \n"+
		"     1. Flakvest..........................................400  \n"+
		"     2. Combat Helmet.....................................100  \n"+
		"     3. Armored Gloves.....................................50  \n"+
		"     4. Steel-reinforced boots.............................50  \n"+
		"     5. Flak-Duster.......................................700  \n"+
		"     7. Combat Armor w/ light............................2500  \n"+
		"     8. Wrist Shield Unit................................8000  \n"+
		"     9. Communications Helmet.............................250  \n"+
      "    10. Night Vision Goggles.............................4500  \n"+
      "    11. Universal Battery................................1000  \n"+
"   [1 hr. Charge for NightVision Goggles, 15 min. for Laptop]\n"+


      "    12. Wrist Communicator................................200  \n"+
		"     ________________________________________________________  \n"+
		"     You may 'purchase #' or 'haggle #' over the price.        \n"+
		"     You may also repair your power armor here.  Just use:     \n"+
	"     'fix armor' for 35000 coins.                              \n");
	return 1;
}

purchase_it(string str){
	int purchase;
	purchase = str;
	if(!present("store_owner", this_object())){
		write("You don't see the store owner here.\n");
		return 1;
	}
	if(!purchase){ write("Usage: purchase 1-8.\n"); return 1; }
	if(purchase == "1"){
		cost = 400;
		item = clone_object("/players/maledicta/town/armor/fvest.c");
		what = "flak vest";
	}
	else if(purchase == "2"){
		cost = 100;
		item = clone_object("/players/maledicta/town/armor/chelmet.c");
		what = "combat helmet";
	}
	else if(purchase == "3"){
		cost = 50;
		item = clone_object("/players/maledicta/town/armor/agloves.c");
		what = "pair of armored gloves";
	}
	else if(purchase == "4"){
		cost = 50;
		item = clone_object("/players/maledicta/town/armor/rboots.c");
		what = "pair of reinforced boots";
	}
	else if(purchase == "5"){
		cost = 700;
		item = clone_object("/players/maledicta/town/armor/fduster.c");
		what = "flak duster";
	}
/*
	else if(purchase == "6"){
		cost = 50000;
		item = clone_object("/players/maledicta/town/armor/parmor.c");
		what = "suit of power armor";
		
	}
*/
	else if(purchase == "7"){
		cost = 2500;
		item = clone_object("/players/maledicta/town/armor/carmor.c");
		what = "suit of combat armor";
	}
	else if(purchase == "8"){
		write(
			"The store owner shakes his head and says, 'I'm sorry, but our supply of wrist\n"+
			"shields has been taken, and we can't expect any new ones in.  Bandits are\n"+
			"hi-jacking the supply lanes between here and the east.  I'll let you know\n"+
		"later if we find out anything. Ok?\n");
		return 1;
		/*
		cost = 8000;
		item = clone_object("/players/maledicta/town/armor/wshield.c");
		what = "wrist shield";
		*/
	}
	else if(purchase == "9"){
		cost = 250;
		item = clone_object("/players/maledicta/town/armor/commhelm.c");
		what = "communications helmet";
	}
	else if(purchase == "10"){
		cost = 4500;
		item = clone_object("/players/vertebraker/misc/mal/ng.c");
		what = "night vision goggles";
	}
	else if(purchase == "11"){
		cost = 1000;
		item = clone_object("/players/vertebraker/misc/mal/b.c");
      item->Units(3600);
		what = "battery";
	}
	else if(purchase == "12"){
		cost = 200;
		item = clone_object("/players/maledicta/town/armor/wristcomm.c");
		what = "wrist communicator";
	}
	else{
		write("The store owner says: I'm sorry, we don't carry that.\n");
		return 1;
	}
	
	if (call_other(this_player(), "query_money", 0) < cost) {
		write("The store owner says: I'm sorry, but you don't have enough for that.\n");
		return 1;
	}
	if(!this_player()->add_weight(item->query_weight())) {
		write("The store owner says: It doesn't look like you can carry that.\n");
		destruct(item);
	return 1; }
	write("You pay the store owner "+cost+" coins and receive a "+what+".\n");
	say(tp->query_name() + " purchases a "+what+".\n");
	move_object(item,this_player());
	tp->add_money(-(cost));
	if(purchase == "6"){
		write_file("/players/maledicta/log/parmor",
		ctime(time())+"  "+HIR+this_player()->query_real_name()+NORM+" Bought power armor.\n");
	}
	return 1;
}



haggle_it(string str){
	int purchase;
	purchase = str;
	if(!present("store_owner", this_object())){
		write("You don't see the store owner here.\n");
		return 1;
	}
	if(!purchase){ write("Usage: purchase 1-8.\n"); return 1; }
	if(purchase == "1"){
		cost = 400;
		haggle = 80;
		item = clone_object("/players/maledicta/town/armor/fvest.c");
		what = "flak vest";
	}
	else if(purchase == "2"){
		cost = 100;
		haggle = 25;
		item = clone_object("/players/maledicta/town/armor/chelmet.c");
		what = "combat helmet";
	}
	else if(purchase == "3"){
		cost = 50;
		haggle = 15;
		item = clone_object("/players/maledicta/town/armor/agloves.c");
		what = "pair of armored gloves";
	}
	else if(purchase == "4"){
		cost = 50;
		haggle = 15;
		item = clone_object("/players/maledicta/town/armor/rboots.c");
		what = "pair of reinforced boots";
	}
	else if(purchase == "5"){
		cost = 700;
		haggle = 200;
		item = clone_object("/players/maledicta/town/armor/fduster.c");
		what = "flak duster";
	}
/*
	else if(purchase == "6"){
		cost = 50000;
		haggle = 10000;
		item = clone_object("/players/maledicta/town/armor/parmor.c");
		what = "suit of power armor";
		
	}
*/
	else if(purchase == "7"){
		cost = 2500;
		haggle = 700;
		item = clone_object("/players/maledicta/town/armor/carmor.c");
		what = "suit of combat armor";
	}
	else if(purchase == "8"){
		write(
			"The store owner shakes his head and says, 'I'm sorry, but our supply of wrist\n"+
			"shields has been taken, and we can't expect any new ones in.  Bandits are\n"+
			"hi-jacking the supply lanes between here and the east.  I'll let you know\n"+
		"later if we find out anything. Ok?\n");
		return 1;
		/*
		cost = 8000;
		haggle = 1800;
		item = clone_object("/players/maledicta/town/armor/wshield.c");
		what = "wrist shield";
		*/
	}
	else if(purchase == "9"){
		cost = 250;
		haggle = 50;
		item = clone_object("/players/maledicta/town/armor/commhelm.c");
		what = "communications helmet";
	}
	else{
		write("The store owner says: I'm sorry, we don't carry that.\n");
		return 1;
	}
	if (call_other(this_player(), "query_money", 0) < (cost + haggle)) {
		write("The store owner says: I'm sorry, but you don't have enough for that.\n");
		return 1;
	}
	
	if(random(this_player()->query_attrib("int"))  > random(owner_int)){
		write(
		"Store Owner says: yeah, you win, but how am I supposed to make a living?\n");
		cost -= random(haggle);
	}
	else{
		write(
		"Store Owner says: You talked me into it, I need to ask more. Thanks.\n");
		if(haggle < 1) haggle = 10;
		cost += random(haggle);
	}
	
	
	if(!this_player()->add_weight(item->query_weight())) {
		write("The store owner says: It doesn't look like you can carry that.\n");
		destruct(item);
	return 1; }
	write("You pay the store owner "+cost+" coins and receive a "+what+".\n");
	say(tp->query_name() + " purchases a "+what+".\n");
	move_object(item,this_player());
	tp->add_money(-(cost));
	if(purchase == "6"){
		write_file("/players/maledicta/log/parmor",
		ctime(time())+"  "+HIR+this_player()->query_real_name()+NORM+" Bought power armor.\n");
	}
	return 1;
}

fix_armor(string str){
	if(!str){
		write("Fix what?\n");
		return 1;
	}
	if(str == "armor"){
		if(this_player()->query_money() < 35000){
			write("You don't have enough coins for that!\n");
			return 1;
		}
		if(present("power_armor_derellia", this_player())){
			present("power_armor_derellia", this_player())->fix_armor();
			write("You pay 35000 coins and have your armor fixed.\n");
			this_player()->add_money(-35000);
			return 1;
		}
		return 1;
	}
	return 0;
}
