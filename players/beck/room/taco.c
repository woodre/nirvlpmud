inherit "room/room";
#include "/players/beck/esc.h"
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=(""+GREEN+"Taco "+OFF+YELLOW+"Bell"+OFF+"");
long_desc=
"This is a Taco Bell restaurant.\n"+
"If you want to order something, take a look at the 'menu'.\n"+
"then 'buy' the item you want.\n"+
"",
items=
({
"menu","Welcome to Taco Bell.  \n"+
"________________________________________________\n"+
"Item                            Price*\n"+
"\n"+
"Soft Taco                            26 cents\n"+
"Nachos                               8 cents\n"+
"\n"+
"________________________________________________\n"+
"    * 1 cent = 100 coins\n"+
"",
});
dest_dir=
({
"players/beck/room/street2.c","exit",
});
}
init() {
::init();
add_action("buy","buy");
}
buy(str) {
	object taco;
	object nachos;
	if(str=="soft taco") {
	if(this_player()->query_money() < 2600) {
	write("You don't have enough gold coins!\n");
	return 1;
	}
	if(!call_other(this_player(), "add_weight", 1)) {
	write("You can't carry that much.\n");
	return 1;
	}
	this_player()->add_money(-2600);
taco=clone_object("/players/beck/heals/soft_taco.c");
	move_object(taco, this_player());
write("You order yourself a tasty taco.\n");
	return 1;
	}
	if(str=="nachos") {
	if(this_player()->query_money() < 800) {
	write("You don't have enough gold coins!\n");
	return 1;
	}
	if(!call_other(this_player(), "add_weight", 1)) {
	write("You can't carry that much.\n");
	return 1;
	}
	this_player()->add_money(-800);
nachos=clone_object("/players/beck/heals/nachos.c");
	move_object(nachos, this_player());
write("You order yourself some delicious nachos.\n");
	return 1;
	}
}
