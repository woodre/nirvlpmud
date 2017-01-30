#include "room.h"

object radar, hawkeye;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!radar || !living(radar)) {
	radar = clone_object("obj/monster");
	call_other(radar, "set_name", "radar");
/* Changed level from 14 to 12 to reflect stats.  -Snow */
	call_other(radar, "set_level", 12);
	call_other(radar, "set_hp", 200);
	call_other(radar, "set_wc", 15);
	call_other(radar, "set_al", 99);
       call_other(radar, "set_ac", 9);
	call_other(radar, "set_short", "Radar");
	call_other(radar, "set_long",
                   "Its just cute little Radar.\n");
	call_other(radar, "set_spell_mess1",
		   "Radar says: Incoming wounded!!!");
	call_other(radar, "set_spell_mess2",
                   "Radar says: I am from Iowa.");
	call_other(radar, "set_chance", 20);
	move_object(radar, this_object());
	money = clone_object("obj/money");
/* Changed from 850 to 600 to conform to coin max for level  -Snow */
        call_other(money, "set_money", random(600));
        move_object(money, radar);
    }
}

FOUR_EXIT("room/crop", "leave",
      "players/hawkeye/room/rd1.c", "north",
   "players/hawkeye/room/lat.c", "west",
   "players/hawkeye/room/newent.c", "barracks",
      "A road",
     "You are on the road that takes you to a M*A*S*H camp" +
"\n" +
       "To the west is a terrible smell, the road continues\n" +
"north and a newbie zone is to the east.\n",1)

init() {
  ::init();
  add_action("ask","ask");
}

ask(str) {
if(!str) {
write("Ask what?");
return 1;}
if(str == "radar") {
write("Okay solider, i guess i have a minute to explain this to you.\n" +
"The problem we are having here is that General MacArthur has lost his\n" +
"corn cob pipe. Your job is to find it.\n\n\n" +
"Radar looks at his clip board\n\n\n" +
"Radar looks at his watch\n\n\n" +
"Go talk to Major Burns about a pass but...\n"+
"he may have lost it to Hawkeye in the\n"+
"card game last night... I don't remember.\n\n\n"+
"But for now, get dressed, We have wounded coming!\n" +
"Radar runs away towards the O.R.\n");
return 1;
}
}
