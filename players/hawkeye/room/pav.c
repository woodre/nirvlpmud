#include "room.h"

object radar, hawkeye;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!radar || !living(radar)) {
	radar = clone_object("obj/monster_lars");
	call_other(radar, "set_name", "radar");
	call_other(radar, "set_level", 14);
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
        call_other(money, "set_money", random(850));
        move_object(money, radar);
    }
}

FOUR_EXIT("room/crop", "leave",
      "players/hawkeye/room/rd1.c", "north",
   "players/hawkeye/room/lat.c", "west",
         "players/hawkeye/room/newent.c", "east",
      "A road",
     "You are on the road that takes you to a M*A*S*H camp" +
"\n" +
       "To the west is a terrible smell, the road continues\n" +
  "north and a newbie zone is to the east.\n"+
  "Doppleganger should take the 'down' entrance here!\n", 1)

init() {
  ::init();
  add_action("down","down");
}

down() {
  if(present("badge", this_player())) {
   write("You go down into the Secret Party room of the Dopples!\n");
 say(capitalize(this_player()->query_name())+" leaves down.\n");
    move_object(this_player(), "players/hawkeye/room/grimm");
tell_room(environment(this_player()), 
 capitalize(this_player()->query_name())+" struts into the Party Room!\n");
   command("look", this_player());
   return 1;
    }
  write("You are not allowed to take that route!!!\n");
  return 1;
}
