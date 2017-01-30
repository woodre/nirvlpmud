#include "std.h"

object ward,beaver,june,wally,jack,money;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    if (!jack || !living(jack)) {
	jack = clone_object("obj/monster");
	call_other(jack, "set_name", "jack");
	call_other(jack, "set_hp", 90);
call_other(jack, "set_ac", 6);
	call_other(jack, "set_wc", 7);
	call_other(jack, "set_al", 200);
	call_other(jack, "set_short", "Captian Jack, Beaver's pet aligator");
	call_other(jack, "set_long",
    "A foot and half long aligator that Beaver raised in his basement.\n");
	call_other(jack, "set_aggressive", 0);
call_other(jack, "set_level", 5);
	move_object(jack, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, jack);
    }

    if (!wally || !living(wally)) {
	wally = clone_object("obj/monster");
	call_other(wally, "set_name", "wally");
	call_other(wally, "set_hp", 140);
call_other(wally, "set_ac", 6);
	call_other(wally, "set_wc", 6);
	call_other(wally, "set_al", 400);
	call_other(wally, "set_short", "Wally, Beaver's older brother");
	call_other(wally, "set_long",
    "This is Beaver's older brother Wally, a swell guy.\n");
	call_other(wally, "set_aggressive", 0);
call_other(wally, "set_level", 6);
	move_object(wally, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(300));
        move_object(money, wally);
    }

    if (!june || !living(june)) {
	june = clone_object("obj/monster");
	call_other(june, "set_name", "june");
	call_other(june, "set_hp", 55);
call_other(june, "set_ac", 3);
	call_other(june, "set_wc", 4);
	call_other(june, "set_al", 600);
	call_other(june, "set_short", "June Cleaver");
	call_other(june, "set_long",
    "This is Beaver's mother, she does housework in her best clothes and NEVER has\n" +
    "a hair out of place.\n");
	call_other(june, "set_aggressive", 0);
call_other(june, "set_level", 3);
	move_object(june, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, june);
    }

    if (!beaver || !living(beaver)) {
	beaver = clone_object("obj/monster");
	call_other(beaver, "set_name", "beaver");
	call_other(beaver, "set_hp", 200);
call_other(beaver, "set_ac", 10);
	call_other(beaver, "set_wc", 10);
	call_other(beaver, "set_al", 650);
	call_other(beaver, "set_short", "The Beaver");
	call_other(beaver, "set_long",
    "Golly Gee.....oh Gosh....It's the Beaver.\n");
	call_other(beaver, "set_aggressive", 0);
call_other(beaver, "set_level", 8);
	move_object(beaver, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(800));
        move_object(money, beaver);
    }

    if (!ward || !living(ward)) {
	ward = clone_object("obj/monster");
	call_other(ward, "set_name", "ward");
	call_other(ward, "set_hp", 135);
call_other(ward, "set_ac", 6);
	call_other(ward, "set_wc", 7);
	call_other(ward, "set_al", 600);
	call_other(ward, "set_short", "Ward Cleaver");
	call_other(ward, "set_long",
    "This is Beaver's Father, a swell guy.\n");
	call_other(ward, "set_aggressive", 0);
call_other(ward, "set_level", 7);
	move_object(ward, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(700));
        move_object(money, ward);
    }

}

ONE_EXIT("players/boltar/lv2/endless.c", "south",
        "The Cleaver's room",
        " You suddenly appear in black and white, this branch is a dead end.\n", 1)
