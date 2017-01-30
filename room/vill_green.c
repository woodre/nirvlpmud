#include <ansi.h>
inherit "room/room";
object disp;

reset(arg) {
   if(!present("hall")) {
      disp = clone_object("players/sandman/NEWBIE/newbie_dispenser");
      move_object(disp, this_object());
   }
   if(!present("news sign"))
     move_object(clone_object("/players/vertebraker/obj/news_sign"), this_object());
   if(!present("bell")) 
    move_object(clone_object("players/boltar/things/green_bell"),this_object());
/*
#ifndef __LDMUD__
  if(!present("scavenger list dispenser")) {
    move_object(clone_object("players/vertebraker/obj/scav_disp"), this_object());
  }
#endif
*/
#if 0
if (!arg) {
move_object(clone_object("/players/earwax/atm.c"), this_object());
}
#if 0   // Rumplemintz - mysql horked at the moment
if (!present("board"))
move_object(clone_object("/object/news/green_board.c"),this_object());
#endif
#else
  if(!present("board")) {
   move_object(clone_object("players/snow/ITEMS/notice"), this_object());
  }
#endif
    if (arg) return;

    set_light(1);
   set_no_clean(1);
    short_desc = BGRN+HIW+"Village Green"+NORM;
    no_castle_flag = 1;
    long_desc = 
  "You are at the legendary "+BGRN+HIW+"Village Green"+NORM+", just south of the Village Church.\n"+
	    "You can see a road further to the east.\n";
    dest_dir = ({"room/church", "north",
		 "room/hump", "west",
		 "room/vill_track", "east"});
}

/* things that are supposed to be in this room as of 5-may-03 -Bp

The Obituary Notice  OBJ(players/llew/Other/misc/obituary#261) [llew ]
A Trashcan  OBJ(players/pathfinder/trashcan#200) [pathfinder ]
A Salvation Army Box  OBJ(players/mizan/closed/sbox#162) [mizan ]
An old ship's bell on a pole  OBJ(players/boltar/things/green_bell#165) [boltar ]
This is the Hall of Apprentices.
New players come here to choose equipment and to prepare
for battle. Enter if you are level 5 or lower.
1 OBJ(players/sandman/NEWBIE/newbie_dispenser#164)

*/

no_light_damage() { return 1; }

