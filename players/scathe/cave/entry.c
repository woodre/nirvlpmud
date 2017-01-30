#include "lib.h"
inherit ROOM;

void create() {
    ::create();
    set_short("Entrance");
    set_long("\
This is the entrance to Scathe's Cave of Joy.\n\
  You feel that if you wear a Badge in this cave, misfortune shall\n\
soon befall you.  This is the Dopple BEATING ZONE!  SO BEAT IT,\n\
BEFORE I BEAT YOU!\n\
There is a shop to the east, a bar to the west, and the monsters\n\
are down.\n");
    set_light(1);
    set_exits(([
        "west": "/players/scathe/bar",
        "east": "/players/scathe/shop",
        "out":  "/room/sea",
        "down": "/players/scathe/cave/cave2",
        ]));
}

void init() {
   ::init();
   add_action("dir","change");
   add_action("dir","pick");
   add_action("dir","charm");
   add_action("dir","gohome");
   add_action("dir","peace");
}
status dir(string arg) {
   write("Skie's magic blocks yours!\n");
   this_player()->hit_player(5);
   return 1;
}
