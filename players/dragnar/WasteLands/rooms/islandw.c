/* 10/11/05 Earwax: Made room land. */

inherit "/players/earwax/housing/land.c";
inherit "room/room";
int x;
init() {
	::init();
	this_player()->set_fight_area();
	add_action("grasp","grasp");
}
reset(arg) {
	if(arg) return;
	if(!arg) x=2;
set_light(5);
short_desc=("Island of the temple");
long_desc=
"The waste here makes are further passage impossible.  As you look at\n"+
"some of the rubble, something catches you eye.  It looks like\n"+
"a skeleton hand...\n",
items=
({
"hand","A bony hand that seems to be reaching for you.  Fear strikes your heart\n"+
"as you think about grasping the cold, white hand"
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/island.c","east",
});

  set_realm_name("Wastelands");
  set_lot_size(6);
  set_cost(250000);
  setup_land();

}
grasp(str) {
	if(str=="hand"){
	write("You grab the hand and feel an evilness enter your soul.  You feel\n"+
"as if Satan has entered your body.  When you open your eyes you see you are in\n"+
"a new place, but the coldness inside you lingers on.\n");
	write("\n");
	say(capitalize(this_player()->query_real_name())+" grasps the hand.\n");
	this_player()->move_player("mysteriously#/players/dragnar/WasteLands/rooms/bridge.c");
	return 1;
	}
}
