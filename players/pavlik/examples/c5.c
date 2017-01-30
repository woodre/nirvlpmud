#include "/players/balowski/lib.h"
#include "/players/reflex/include/ansi.h"
inherit ROOM;

    void create() {
        ::create();

    add_monster("/players/reflex/realms/tiny/monsters/scorpion", 4, 2);
    add_monster("/players/reflex/realms/tiny/monsters/vulture", 4, 2);
    add_monster("/players/reflex/realms/tiny/monsters/wurm", 2, 1);
    set_monster_frequency(120);

    set_short("A small desert");
    set_long(
	"You are in a small desert.\n"+
	"Dunes stretch out before you, obscuring your view.\n"+
	"Your throat burns, parched instantly by the dry air.\n"+
	"Through the swirling sand you think you see an oasis\n"+
	"to the north...or is it to the east..?  Maybe west.\n"+
	"Hard to tell in all this sand...\n"
        );
    set_items(([
	"dunes" :
	"Sand dunes obscure your vision in every direction.\n",
	"sand" :
	"sand is everywhere, it will take months to get it\n"+
	"all out of your shoes!\n",
	"oasis" :
	"You think you see it to the north, but it could be\n"+
	"anywhere...\n",
        ]));
    set_sounds(([
	"default" :
	"You hear the wind tearing through the dunes.\n",
        ]));
    set_smells(([
	"default" :
	"The hot air scorches your throat and nose.\n",
        ]));
    set_chat_frequency(30);
    load_chats(({
	"A vulture circles overhead...\n",
	"Sand swirls in the wind.\n",
	"The ground "+BOLD+"RuMbLeS"+NORM+" under your feet!\n",
	"Something skitters past your feet...\n",
	"The sun beats down...\n",
       }));
    set_exits(([
        "north" : "/players/reflex/realms/tiny/center",
        "east" : "/players/reflex/realms/tiny/c4",
        "west" : "/players/reflex/realms/tiny/c6",
        "northeast" : "/players/reflex/realms/tiny/c3",
        "northwest" : "/players/reflex/realms/tiny/c7",
        ]));
    set_light(1);
    replace_program(ROOM);
}
