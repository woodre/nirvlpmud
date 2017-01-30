#include <ansi.h>
#define NAME "Angel"
#define DEST "room/lanceroad3"

id(str) { return str == "stargate" || str == "stargate sg1"; }

short() {
    return " "+HIB+"STARGATE /-\\"+NORM+" ";
}

long() {
    write("Inside of this military base lies the secret Stargate.\n");
    write("The gates are heavily guarded but, it appears the 'rings'\n");
    write("are unattended. Maybe you could use the 'rings' to get inside.\n");
}

init() {
    add_action("enter","rings");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    " is allowed to pass the heavily monitored gate and transported inside.\n");
    this_player()->move_player(
    "and is transported into the military base#/players/angel/area/stargate/room/sg1.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}


reset(arg) {
    if (arg)
        return;
    move_object(this_object(), DEST);
    load_it();
}

is_castle(){return 1;}

load_it(){
 /* 03/24/06 Earwax: added mason mini-guild object to here */
  "/players/angel/masons/mgob.c"->load_up_you_filthy_bugger();
  /*This is for the reward belt item*/
  "/players/angel/rewards/belt_02.c"->load_this_up_nukka();
}