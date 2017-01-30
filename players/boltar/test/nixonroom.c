#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
  }
look(str) {
   if (!str) {
   return 0;
  }
 if (str == "at equipment" || str == "equipment") {
  write("It looks like a large metal box.\n");
  return 1;
  }
if (str == "books" || str == "shelves" || str == "at shelves" || str == "at books") {
 write ("There are many, many books on the shelves.\n");
   return 1;
  }
return 0;
}
int count;
object nixon;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object tape;
    object watc;
    object headset;
  if (!present("headset")) {
   headset = clone_object("players/boltar/things/hedset.c");
   move_object(headset, this_object());
 }
    if (!nixon || !living(nixon)) {
	nixon = clone_object("obj/monster_new.c");
call_other(nixon, "set_name", "nixon");
call_other(nixon, "set_alias", "richard");
call_other(nixon, "set_short", "Richard Nixon"); 
call_other(nixon, "set_object", this_object());
	call_other(nixon, "set_hp", 350);
call_other(nixon, "set_ac", 9);
	call_other(nixon, "set_wc", 15);
	call_other(nixon, "set_al", 50);
call_other(nixon, "set_whimpy");
	call_other(nixon, "set_long",
		   "The great former president of the United States himself.\n");
	call_other(nixon, "set_aggressive", 0);
call_other(nixon, "set_level", 15);
	call_other(nixon, "set_spell_mess1",
		   "Richard does the double victory.");
	call_other(nixon, "set_spell_mess2",
		   "Richard does the double victory");
	call_other(nixon, "set_chance", 40);
move_object(nixon, this_object());
call_other(nixon, "set_spell_dam", 12);
call_other(nixon, "set_chat_chance", 60);
call_other(nixon, "load_chat", "Richard says: I'm not a crook!\n");
call_other(nixon, "load_chat", "Richard says: My memoirs are the basis for my comeback.\n");
call_other(nixon, "set_a_chat_chance", 60);
call_other(nixon, "load_a_chat", "Richard says: The tapes, the tapes I must burn the tapes!\n");
call_other(nixon, "load_a_chat", "Richard says: Resign? Never!!!!\n");
	money = clone_object("obj/money");
        call_other(money, "set_money", random(600));
        move_object(money, nixon);
tape = clone_object("obj/treasure");
        call_other(tape, "set_id", "player");
        call_other(tape, "set_short", "A tape player");
        call_other(tape, "set_value", 300);
        call_other(tape, "set_long", "A player for audio tapes.\n");
        call_other(tape, "set_weight", 2);
        move_object(tape, nixon);
  watc=clone_object("players/boltar/things/watch.c");
  move_object(watc, nixon);
    }
}

THREE_EXIT("players/boltar/test/nixonbar.c", "west",
 "players/boltar/test/plastiroom.c", "north",
 "players/boltar/test/secserv.c", "east",
        "Nixon's office",
  " Shelves full of books cover the walls of this room.  In the southeast \n"+
" corner you notice some strange metalic equipment. It could be anything.\n" +
" You also notice very nice old desk in the northwest corner and that you\n" +
" are standing on some very soft carpeting.\n", 1)
