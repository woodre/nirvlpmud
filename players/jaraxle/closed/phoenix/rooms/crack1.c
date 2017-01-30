/*  10/08/06 - Rumplemintz: moved inherit above #include  */
/*  10/08/06 - Rumplemintz: removed trailing ; in #include  */

inherit "/players/jaraxle/room.c";
#include "/players/jaraxle/define.h"
#include "/players/jaraxle/closed/phoenix/mons/random.h"

reset(arg) {
    if(arg) return;
    set_light(1);
    get_random_mob();
    short_desc = "Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM;
    long_desc =
    "  A large cavern of stone and dirt.  The cavern\n"+
    "seems to be dug deep into the ground beside the tower.\n"+
    "A slight breeze enteres the room from the large\n"+
    "crack on the west side of the rock wall.\n";
    add_item("crack","A large crack in the wall you can squeeze through");
    add_item("tower","Made of solid stone, the tower rises high above the land");
    add_object("/players/jaraxle/closed/phoenix/mons/mon3_2.c");
}

init(){
    ::init();
    add_action("enter_door","squeeze");
}

enter_door(str){
    if(!str) return (notify_fail("You may enter the door.\n"), 0);
    if(str == "crack" || str == "through crack"){
	write("You manage to squeeze through the crack.\n");
	this_player()->move_player("through the crack#/players/jaraxle/closed/phoenix/rooms/floor2b");
	return 1; }
    notify_fail("Squeeze through what?\n"); return 0; }
