#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"Abandoned Mine Shaft"+NORM);
   set_long("This is an abandoned mine shaft.  Long disused and in bad need\n\
of cleaning.  A Rope pulley descends into the darkness.\n\
Perhaps one could use it to venture onward into the depths\n\
of the underways.\n");
   set_light(1);
   add_property("no_fight");
   
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "rope", "A sturdy rope",
         "pulley", "This simple contraption seems to let one go up or down on the rope"
         });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm1.c", "mine",
         "room/mine/tunnel2", "out"});
   move_object(clone_object("/players/khrell/area/khs.c"), this_object());
}
