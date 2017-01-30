#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Drak Cavern");
    set_long("\
You have entered the cavern of the Drak Lord.\n\
He measures you with a certain amount of respect for surviving his\n\
guards, but also with the confidence that you cannot withstand his\n\
might.  Consider carefully whether you can best him or not.....\n");
    set_light(1);
    set_exits(([
        "east": "/players/scathe/cave/caved13",
        ]));
}

void reset(int arg) {
    object monster;
    int x;

    ::reset(arg);
    if (!present("drak", this_object())) {
        x = 1;
        while (x--) {
            monster=clone_object("/players/scathe/monsters/drak8");
            move_object(monster,this_object());
        }
    }
}

/* can anybody find meaning in this? from the days of thieves?  --Bal
init(){
   ::init();
   add_action("dir","pick");
}
dir(){
   write("The Lord Drak gnaws off your hand.\n");
   this_player()->hit_player(20);
   return 1;
}
*/
