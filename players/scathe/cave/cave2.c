#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Newbie Entrance");
    set_long("\
This is the entrance to Scathe's House of Newbie Horrors.  Procede\n\
south if you are level 7 and under, otherwise, keep going down....\n");
    set_light(1);
    set_exits(([
        "up":   "/players/scathe/cave/entry",
        "down": "/players/scathe/cave/caved",
        "south":"/players/scathe/cave/cave3",
        ]));
}

init() {
  ::init();
  add_action("south","south");
}

south(string arg) {
   if (this_player()->query_level() > 7){
        write("I said level 7 or lower!\n");
        return 1;
   }
}
