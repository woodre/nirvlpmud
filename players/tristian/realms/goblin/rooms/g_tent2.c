#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Goblin Wizards Tent"; 

long_desc =
    " The inside of this tent is hot and the smell of sulfer smoke hangs\n"+
    "heavy. A low cot is off to one side and balls of fire just hang in\n"+
    "the air shedding light over the contents of the area. Books and scrolls\n"+
    "lay all over the area. A pentagram is inscribed into the center of the floor.\n";

items = ({

    "tent", 
        "A better made tent than the others in the camp, you suspect they were\n"+
        "pillaged from some unlucky caravan",
    "cot",
        "A small bed used for sleeping",
    "balls",
        "Magical balls of fire shedding light across the interior of the tent",
    "books",
        "Spell books, written in the gutteral language of the goblin, they have\n"+
        "little value since you don't read their language",
    "scrolls",
        "Spell scrolls, written in the gutteral language of the goblin. The figures\n"+
        "dance across the page making reading impossible",
    "pentagram",
        HIR+"             ,,---n---,,               \n"+
        "        ,--**   l   l  **--,          \n"+
        "      ,*        |   |        *,        \n"+
        "    ,'          |   |          *,      \n"+
        "   l           l     l           l     \n"+
        "  l           |       |           l    \n"+
        " ,=-----------+-------+-----------=,   \n"+
        " l *-,       l         l       ,-* l   \n"+
        ",'    *,    |           |    ,*    ',  \n"+
        "|       *-, |           | ,-*       |  \n"+
        "|          )-,         ,-(          |  \n"+
        "*         |   *,     ,*   |         *  \n"+
        " l       l      *-,-*      l       l   \n"+
        " *,     |      ,-' '-,      |     ,*   \n"+
        "  l     |    ,*       *,    |     l    \n"+
        "   l   l  ,-*           *-,  l   l     \n"+
        "   *,|,-*                 *-,|,*       \n"+
        "     *,                     ,*         \n"+
        "       *--,,           ,,--*           \n"+
        "           '**-------**'               "+NORM+"",
    "stand",
        "A 3 legged stand holding up the brazier, the legs are carved in arcane\n"+
        "runes",
    "symbols",
        "Arcane runes drawn to focus the goblin god's power",
    "runes",
        "Symbols of the goblin gods, a lightning bolt, and some clouds",
    "lightning bolt",
         "A crude drawing of a zig zag lightning bolt, symbols to some\n"+
         "goblin sky god",
    "lightning",
         "A crude drawing of a zig zag lightning bolt, symbols to some\n"+
         "goblin sky god",
    "bolt",
         "A crude drawing of a zig zag lightning bolt, symbols to some\n"+
         "goblin sky god",
    "clouds",
         "A crude drawing of a cloud, symbols to some goblin sky god",
    "cloud",
         "A crude drawing of a cloud, symbols to some goblin sky god",
    "instrument",
         "A couple of shrunken heads, and some bat wings, and other\n"+
         "items you associate with black magic",
    "fire",
        "Magical balls of fire shedding light across the interior of the tent",
    "heads",
         "Some unfortunate souls who became experiments for the shaman",
    "wings",
         "The wings off of an ordinary fruit bat",
});


    if(!present("goblin",this_object()))
        move_object(
            clone_object(NPC+"goblin_wizard.c"),
        this_object());


    dest_dir = ({

       RMS+"g_room11.c",    "out",

    });
}

      init() {
        ::init();
           add_action("Smell","smell");
}

  Smell(str) {
        if(!str || str == "air") {
            write("The air is thick with the smell of burning sulfer.\n");
    return 1;
}

}