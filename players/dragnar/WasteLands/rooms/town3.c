/* 10/11/05 Earwax: Made room land. */

inherit "/players/earwax/housing/land.c";
inherit "room/room";
int x,y;
init() {
	::init();
	this_player()->set_fight_area();
	add_action("move","move");
	add_action("east","east");
	add_action("north","north");
}
reset(arg) {
	if(arg) return;
	if(!arg) x=1;
y=1;
set_light(5);
short_desc=("Wasteland's Town");
long_desc=
"Here the remains of the road turns east, but a huge tower has fallen\n"+
"across it.  Past the tower, farther to the east, the rest of the town\n"+
"looks much like this side of the town.  With all of the pavement and\n"+
"concrete around it looks as if the only way is back to the north.\n",
items=
({
"tower","It looks like it is impossible to move because of it's size, but maybe if\n"+
"you are very strong you have a chance..."
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/town2.c","north",
});

  set_realm_name("Wastelands");
  set_lot_size(2);
  set_cost(100000);
  setup_land();

}
move(str) {
	if(str=="tower"){
	if(this_player()->query_level() < 18) {
	write("You are not strong enough.\n");
	return 1;
	}
	if(y < 2 && this_player()->query_mhp() > 260) {
	x=x+8;
	y=y+6;
	write("You use every ounce of strength to move the tower.\n");
	say(capitalize(this_player()->query_real_name())+" moves the tower.\n");
	return 1;
	}
	else if(y > 2) {
	write("The tower has been moved already.\n"+
"You may be able to go east now.\n");
	return 1;
	}
	}
}
east() {
	if(x > 2) {
	call_other(this_player(),"move_player","east#/players/dragnar/WasteLands/rooms/town4.c");
	return 1;
	}
	else if(x < 2) {
	write("The tower blocks your way.\n");
	return 1;
	}
}
north() {
	call_other(this_player(),"move_player","north#/players/dragnar/WasteLands/rooms/town2.c");
	return 1;
}
