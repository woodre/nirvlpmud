#include "/players/maledicta/ansi.h"
/* #include "/players/maledicta/cont/outpost/buy.h" */
#define USER environment()
#define PATH "/players/maledicta/cont/rooms/599.c"
string curr_room;

reset(arg){
	if(arg) return;
	curr_room = "main";
	call_out("emergency", 120);
}

id(str){ return str == "cityinabottle"; }

emergency(){ destruct(this_object()); return 1; }

init(){
	if(!environment()) return;
#ifndef __LDMUD__
   add_action("no_good"); add_xverb("");
#else
   add_action("no_good", "", 3);
#endif
	add_action("purchase", "purchase");
	add_action("purchase", "buy");
	add_action("list", "list");
	add_action("sell", "sell");
	add_action("leave","leave");
	add_action("smith", "weapon");
	add_action("smith", "1");
	add_action("potion","potion");
	add_action("potion", "2");
	add_action("armorer", "armor");
	add_action("armorer", "3");
	add_action("bar", "bar");
	add_action("bar", "4");
	add_action("temple", "temple");
	add_action("temple", "5");
	add_action("shop", "shop");
	add_action("shop", "6");
	add_action("invent", "inventory", 1);
	add_action("score", "score", 2);
	
}

no_good(str){
	menus();
	return 1;
}

score(){
	this_player()->score();
	write("\n\nHit 'enter' to see the menu.\n");
	return 1;
}

invent(){
	this_player()->inv();
	write("\n\nHit 'enter' to see the menu.\n");
	return 1;
}



leave(){
	if(curr_room != "main"){
		write("\nYou exit the shop.\n\n");
		curr_room = "main";
		menus();
		return 1;
	}
	else{
		write("You leave the town.\n");
		move_object(this_player(), PATH);
		destruct(this_object());
		return 1;
	}
}

list(obj){
	if(curr_room == "main"){ menus(); return 1; }
	else if(curr_room == "shop"){
		call_other("room/store", "inventory", obj);
		return 1;
	}
	else{
		cat("/players/maledicta/cont/outpost/docs/"+curr_room+"_list");
	}
	my_status();
	return 1;
}





shop(){
	if(curr_room != "main"){ write("You must leave first.\n"); return 1; }
	write("You enter the local shop.\n");
	curr_room = "shop";
	menus();
	return 1;
}


smith(){
	if(curr_room != "main"){ write("You must leave first.\n"); return 1; }
	write("You enter the Weaponsmith's shop.\n");
	curr_room = "smith";
	menus();
	return 1;
}

potion(){
	if(curr_room != "main"){ write("You must leave first.\n"); return 1; }
	write("You enter the Potion's shop.\n");
	curr_room = "potion";
	menus();
	return 1;
}

armorer(){
	if(curr_room != "main"){ write("You must leave first.\n"); return 1; }
	write("You enter the Armorer's shop.\n");
	curr_room = "armor";
	menus();
	return 1;
}

bar(){
	if(curr_room != "main"){ write("You must leave first.\n"); return 1; }
	write("You enter the local bar.\n");
	curr_room = "bar";
	menus();
	return 1;
}

temple(){
	if(curr_room != "main"){ write("You must leave first.\n"); return 1; }
	write("You enter the Temple.\n");
	curr_room = "temple";
	menus();
	return 1;
}


sell(item) {
	object ob;
	if(curr_room != "shop"){ menus(); return 1; }
	if (!item){ write("Sell what?\n"); menus(); return 1; }
	if (item == "all") {
		object next;
		ob = first_inventory(this_player());
		while(ob) {
			next = next_inventory(ob);
			if (!ob->drop() && ob->query_value()) {
				write(ob->short() + ":\t");
				do_sell(ob);
			}
			ob = next;
		}
		write("Ok.\n");
		return 1;
	}
	ob = present(item, this_player());
	if (!ob)
	ob = present(item, this_object());
	if (!ob) {
		write("No such item ("); write(item); write(") here.\n");
		return 1;
	}
	do_sell(ob);
	return 1;
}

do_sell(ob) {
	int value, do_destroy;
	value = ob->query_value();
	if (!value) {
		write(ob->short() + " has no value.\n");
		return 1;
	}
	if (environment(ob) == this_player()) {
		int weight;
		if (call_other(ob, "drop", 0)) {
			write("I can't take it from you!\n");
			return 1;
		}
		weight = call_other(ob, "query_weight", 0);
		call_other(this_player(), "add_weight", - weight);
	}
	if (value > 6000)
	do_destroy = 1;
	if(ob->query_dest_flag()) do_destroy = 1;
	if (value > 1000 && value < 1400) {
		write("The shop is low on money...\n");
		value = 1000;
	}
	else if (value >= 1400) {
		write("The shop is low on money...\n");
		value = 1000 + random(100);
	}
	write("You get "); write(value); write(" gold coins.\n");
	say(call_other(this_player(), "query_name", 0) + " sells " +
	call_other(ob, "short", 0) + ".\n");
	call_other(this_player(), "add_money", value);
	if (do_destroy) {
		write("The valuable item is hidden away.\n");
		destruct(ob);
		return 1;
	}
	call_other("room/store", "store", ob);
	return 1;
}



purchase(str){
	if(curr_room == "main") menus(); return 1;
	if(!str){ write("purchase/buy what?\n"); menus(); return 1; }
	if(curr_room == "shop"){
		call_other("room/store", "buy", str);
		return 1;
	}
	else if(curr_room == "smith"){
		weapon_buy(str, this_player());
		return 1;
	}
	else if(curr_room == "armor"){
		armor_buy(str, this_player());
		return 1;
	}
	else if(curr_room == "potion"){
		potion_buy(str, this_player());
		return 1;
	}
	else if(curr_room == "bar"){
		bar_buy(str, this_player());
		return 1;
	}
	else if(curr_room == "temple"){
		temple_buy(str, this_player());
		return 1;
	}
	else{ menus(); return 1; }
	return 1;
}


menus(){
	if(curr_room == "main"){
		cat("/players/maledicta/cont/outpost/docs/main");
	}
	else{
		cat("/players/maledicta/cont/outpost/docs/"+curr_room+"");
	}
	my_status();
	return 1;
}

my_status(){
	USER->print_monitor();
	write("Coins: "+HIM+USER->query_money()+NORM+"\n");
	return 1;
}

