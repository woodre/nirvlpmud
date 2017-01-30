#define NAME "Khrell"
#define DEST "room/mine/tunnel2"
#include <ansi.h>
#include "/players/khrell/define.h"


id(str) { return str == "shaft"; }

short() {
    return "A Mine Shaft";
}

long() {
    write("A mine shaft\n");
}

init() {
  add_action("enter", "enter");
}

enter(str){ 
    if (!id(str))
    {
	    notify_fail("What are you trying to enter?\n");
	    return 0;
}
   this_player()->move_player("enters the shaft#/players/khrell/shaft.c");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
