#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset()
{
    object gambler, money, deck;
    int i;

    i = 0;
    if (!present("gambler")) {
	while(i<4) {
	    i += 1;
	    gambler = clone_object("obj/monster");
	call_other(gambler, "set_name", "gambler");
	call_other(gambler, "set_hp", 80);
call_other(gambler, "set_ac", 6);
	call_other(gambler, "set_wc", 12);
	call_other(gambler, "set_al", 0);
call_other(gambler, "set_short", "A western gambler");
	call_other(gambler, "set_long",
  "A man dressed in expensive western style clothing.\n");
	call_other(gambler, "set_aggressive", 0);
call_other(gambler, "set_level", 4);
	    move_object(gambler, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(350));
        move_object(money, gambler);
deck = clone_object("obj/treasure");
call_other(deck, "set_id", "deck");
call_other(deck, "set_short", "A deck of cards");
call_other(deck, "set_long", "A deck of cards\n");
call_other(deck, "set_alias", "cards");
call_other(deck, "set_value", 15);
call_other(deck, "set_weight", 1);
move_object(deck, gambler);
	}
    }
}

TWO_EXIT("players/boltar/lv2/wildwest3.c", "east",
       "players/boltar/sprooms/dead_office.c", "down",
 "The gambler's place",
  "This is a small room decorated in the style of the old west, there is a table\n" +
 "and some chairs in the center.\n" +
 "There is a small staircase leading down in the far corner of the room.\n", 1)
