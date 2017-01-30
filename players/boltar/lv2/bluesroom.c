#include "std.h"

object elwood,jake;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money,harmonica;
    if (!jake || !living(jake)) {
	jake = clone_object("obj/monster");
	call_other(jake, "set_name", "jake");
	call_other(jake, "set_hp", 120);
call_other(jake, "set_ac", 6);
	call_other(jake, "set_wc", 7);
	call_other(jake, "set_al", 200);
	call_other(jake, "set_short", "Joliet Jake Blues");
	call_other(jake, "set_long",
    "Yep, it's Jake alright. If your lucky maybe he will sing for you.\n");
	call_other(jake, "set_aggressive", 0);
call_other(jake, "set_level", 7);
call_other(jake, "set_chat_chance", 10);
call_other(jake, "load_chat", "Jake says: Yes! Yes! I have seen the Light!\n");
call_other(jake, "load_chat", "Jake says: The Band! The Band, Elwood!, The Band!\n");
call_other(jake, "load_chat", "Jake sings Gimme some lovin'.\n");
call_other(jake, "load_chat", "Jake sings Soul Man.\n");
	move_object(jake, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, jake);
    }

    if (!elwood || !living(elwood)) {
	elwood = clone_object("obj/monster");
	call_other(elwood, "set_name", "elwood");
	call_other(elwood, "set_hp", 110);
call_other(elwood, "set_ac", 6);
	call_other(elwood, "set_wc", 7);
	call_other(elwood, "set_al", 200);
	call_other(elwood, "set_short", "Elwood Blues");
	call_other(elwood, "set_long",
    "It's the harmonica man himself, Elwood Blues.\n");
	call_other(elwood, "set_aggressive", 0);
call_other(elwood, "set_chat_chance", 10);
call_other(elwood, "set_level", 7);
call_other(elwood, "load_chat", "Elwood says: We're on a mission from God.\n");
call_other(elwood, "load_chat", "Elwood says: No maam, we're musicians.\n");
call_other(elwood, "load_chat", "Elwood sings the theme from Rawhide.\n");
call_other(elwood, "load_chat", "Elwood sings Stand by your man.\n");
	move_object(elwood, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(200));
        move_object(money, elwood);
harmonica = clone_object("players/boltar/things/harm");
     
     call_other(harmonica, "set_id", "harmonica");
     call_other(harmonica, "set_weight", 1);
move_object(harmonica, elwood);
    }

}

ONE_EXIT("players/boltar/lv2/level2room3.c", "north",
        "The Blues Brothers are here",
        " Before you, you see a stage with chicken-wire in front of it. And a sign\n" +
        " that reads Bob's Country Bunker.", 1)
