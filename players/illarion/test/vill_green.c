inherit "players/illarion/test/room";
object disp;

reset(arg) {
   if(!present("suggestion box")) {
      move_object(clone_object("/obj/box"), this_object());
   }
   if(!present("dispenser")) {
      disp = clone_object("players/sandman/NEWBIE/newbie_dispenser");
      move_object(disp, this_object());
   }
   if(!present("bell")) 
    move_object(clone_object("players/boltar/things/green_bell"),this_object());
    if (arg) return;

    set_light(1);
   set_no_clean(1);
    short_desc = "Village green";
    no_castle_flag = 1;
    long_desc = 
	"You are at an open green place south of the village church.\n" +
	    "You can see a road further to the east.\n";
    dest_dir = ({"room/church", "north",
		 "room/hump", "west",
		 "room/vill_track", "east"});
}

/* things that are supposed to be in this room as of 5-may-03 -Bp

The Obituary Notice  OBJ(players/llew/Other/misc/obituary#261) [llew ]
Announcement bulletin board(28 msgs)  OBJ(players/snow/ITEMS/notice#259) [snow ]
A vending machine  OBJ(players/mythos/prac/vending#217) [mythos ]
A Trashcan  OBJ(players/pathfinder/trashcan#200) [pathfinder ]
A Salvation Army Box  OBJ(players/mizan/closed/sbox#162) [mizan ]
An old ship's bell on a pole  OBJ(players/boltar/things/green_bell#165) [boltar ]
This is the Hall of Apprentices.
New players come here to choose equipment and to prepare
for battle. Enter if you are level 5 or lower.
1 OBJ(players/sandman/NEWBIE/newbie_dispenser#164)
Suggestion Box  OBJ(obj/box#163) [0 ]

*/
query_no_fight() {return 1;}
