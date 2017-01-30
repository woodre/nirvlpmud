#include "std.h"
id(str) { return str == "faucet"; }
string kick;
int x, y;
short() { return "A faucet"; }
long() {
    cat("/players/mizan/etheriel/environs/FAUCET");
	return 1;
	}
init() {
	add_action("fill","fill");
	}
fill(str) {
  object thing;
	if(!str) return 0;
	sscanf(str, "%d", x);
	y=x*60;
	if(x>1000) {
	write("That is too high a number.\n");
	write_file("/players/mizan/logs/jug.log", (this_player()->query_name())+" attempted an overfill of "+x+"\n");
	return 1;
	}
	if(x<1) {
	write("You can't do that.\n");
	write_file("/players/mizan/logs/jug.log", (this_player()->query_name())+" attempted to underfill the jug by "+x+"\n");
	return 1;
	}
	if(call_other(this_player(), "query_money", 0) < y) {
	write("You only have ["+(this_player()->query_money())+
	"] gold! It would cost ["+y+"] gold\n"+
	"to add ["+x+"] units of healing to the jug.\n");
	return 1; }

  call_other(this_player(), "add_money", 0-y); 
  thing = present("MI-jug", this_player());
    if(!thing) return 0;
  thing->add_charge(x);
	return 1; }
