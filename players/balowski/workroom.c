#include "lib.h"
inherit ROOM;

void create()
{
    ::create();
    set_short("The channel couch");
    set_long("\
It is early morning and you are standing on a big lawn surrounded by a\n\
forest of beech trees.  Your naked feet are soothed by the cool green\n\
grass as you wade towards the white bench in the middle of the lawn.\n\
Three trails lead away from here. You can go out, post, or church.\n");
    set_items(([
"bench" : "\
It is a sturdy wooden bench painted chalk-white.\n\
You can sit on it.\n",
({ "lawn", "grass", }) : "It is green and dewy.\n",
    ]));
    set_exits(([
        "out"   : "/players/balowski/guild/room/throne",
        "church": "/room/church",
        "post"  : "/room/post",
    ]));
    load_chats(({
	"Somewhere a blackbird is singing its hymn to the sunrise.\n",
/*
	"Far away you can hear a rooster go cock-a-doodle-do.\n",
*/
    }));
    set_chat_frequency(0);
    set_light(1);
}

void init()
{
    ::init();
    add_action("cmd_sit", "sit");
}

status cmd_sit(string arg)
{
    if (arg != "bench" && arg != "on bench") {
	notify_fail("Sit on what?\n");
	return 1;
    }
    write("You wipe off some dew and sit down on the bench.\n");
    say(this_player()->query_name() + " takes a seat on the bench.\n");
    return 1;
}
