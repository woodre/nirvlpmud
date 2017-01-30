#include "/players/balowski/lib.h"
#include "/players/reflex/include/ansi.h"
inherit ROOM;

    void create() {
        ::create();

    set_short("A clearing in a forest");
    set_long(
	"You are in a small clearing deep in a forest...\n"+
	"You are standing in the middle of a small mound in\n"+
	"in a large forest.  The trees seem to form a ring\n"+
	"around the clearing, and the mound is just tall\n"+
	"enough for you to see mountain walls all around\n"+
	"the valley you appear to be in.\n"+
	"\nThere is a shimmering "+BLU+"portal"+NORM+" here.\n"+
	"There is a sign here.\n"
        );
    set_items(([
        "forest" :
        "You can see trees all the way to the mountains in\n"+
	"the distance in all directions.\n",
	"clearing" :
	"Short grass grows in this small clearing in the\n"+
	"middle of the forest.  The ground is raised here in\n"+
	"a small mound.\n",
	"mound" :
	"A small raised mound just high enough to let you\n"+
	"see the mountains in the distance.\n",
	"mountains" :
	"High mountains seem to ring this valley in all\n"+
	"directions...\n",
	"valley" :
	"A forested valley hidden deep in the mountains...\n",
	"portal" :
	"You fell through this portal when you arrived here.\n"+
	"It hovers about a foot off the ground and you could\n"+
	"probably step back through it...\n",
        "sign" :
        "<>==============================<>\n"+
        "|| A note about this area -     ||\n"+
        "|| Exits are not shown, you can ||\n"+
        "|| go any direction that does   ||\n"+
        "|| not say otherwise in the     ||\n"+
	"|| description.                 ||\n"+
        "|| Type <help_realm> to get a   ||\n"+
        "|| list of what is different    ||\n"+
        "|| here.  Hope you like it. ;>  ||\n"+
        "||                              ||\n"+
        "||                     -Reflex  ||\n"+
        "<>==============================<>\n",
        ]));
    set_sounds(([
        "default" :
        "It is silent around this clearing, unusual for a\n"+
	"forest...\n",
        ]));
    set_smells(([
        "default" :
        "You smell mildew and wetness in the air.\n",
        "grass" :
        "You smell dirt.\n",
        ]));
    set_chat_frequency(100);
    load_chats(({
        "The breeze ruffles your hair.\n",
	"The "+BLU+"portal"+NORM+" shimmers...\n",
        }));
    set_exits(([
        "north" : "/players/reflex/realms/forest/c1",
        "south" : "/players/reflex/realms/forest/c5",
        "east" : "/players/reflex/realms/forest/c3",
        "west" : "/players/reflex/realms/forest/c7",
        "northeast" : "/players/reflex/realms/forest/c2",
        "northwest" : "/players/reflex/realms/forest/c8",
        "southeast" : "/players/reflex/realms/forest/c4",
        "southwest" : "/players/reflex/realms/forest/c6",
        ]));
    set_light(1);
    replace_program(ROOM);
}

init() {
   ::init();
   add_action("help_realm","help_realm");
}

help_realm() {
   write(
        "<>--------------------------------------------------<>\n"+
        "   This realm is different than most.  There are a    \n"+
        "   few things that might help you in your quest...    \n"+
        "<>--------------------------------------------------<>\n"+
        "   Commands -                                         \n"+
        "                                                      \n"+
        "   Smell:                                             \n"+
        "   Description - Use this to smell your environment.  \n"+
        "   Usage - 'smell' or 'smell <item>'                  \n"+
        "                                                      \n"+
        "   Listen:                                            \n"+
        "   Description - Listen to sounds around you.         \n"+
        "   Usage - 'listen' or 'listen <sound>'               \n"+
        "                                                      \n"+
        "   Search:                                            \n"+
        "   Description - Search the room or a specific item.  \n"+
        "   Usage - 'search' or 'search <item>'                \n"+
        "<>--------------------------------------------------<>\n"+
        "   Tips -                                             \n"+
        "                                                      \n"+
        "   Listen frequently.  Exits are not listed, so read  \n"+
        "   room descripts carefully.  You can go most any     \n"+
        "   direction, you may want to map your course so you  \n"+
        "   don't get lost.  There are many things hidden in   \n"+
        "   the forest, be on the lookout for them.  Beware    \n"+
        "   of ambushes...                                     \n"+
        "<>--------------------------------------------------<>\n"
        );
   return 1;
}
