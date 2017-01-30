#include "std.h"

object cyberman;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object cyhead;
    if (!cyberman || !living(cyberman)) {
	cyberman = clone_object("obj/monster");
	call_other(cyberman, "set_name", "cyberman");
call_other(cyberman, "set_alias", "man");
	call_other(cyberman, "set_level", 12);
	call_other(cyberman, "set_hp", 200);
call_other(cyberman, "set_ac", 10);
	call_other(cyberman, "set_wc", 10);
	call_other(cyberman, "set_al", -400);
call_other(cyberman, "set_whimpy");
	call_other(cyberman, "set_short", "A cyberman");
	call_other(cyberman, "set_long",
		   "A metalic man like thing.\n");
	call_other(cyberman, "set_aggressive", 1);
	call_other(cyberman, "set_spell_mess1",
		   "The cyberman shoots his attacker with his energy weapon.");
	call_other(cyberman, "set_spell_mess2",
		   "The cyberman shoots you with his high power energy weapon!!!");
	call_other(cyberman, "set_chance", 50);
	move_object(cyberman, this_object());
call_other(cyberman, "set_spell_dam", 25);
	money = clone_object("obj/money");
        call_other(money, "set_money", random(250));
        move_object(money, cyberman);
cyhead = clone_object("obj/armor");
call_other(cyhead, "set_id", "cyhead");
call_other(cyhead, "set_name", "cyberman's head");
call_other(cyhead, "set_alias", "head");
call_other(cyhead, "set_weight",4);
call_other(cyhead, "set_value",600);
call_other(cyhead, "set_type", "helmet");
call_other(cyhead, "set_ac", 2);
call_other(cyhead, "set_arm_light", 1);
        call_other(cyhead, "set_short", "A cyberman's head");
   call_other(cyhead, "set_long", "The metal head of a cyberman. It looks like it can be worn.The eyes seem to glow.\n");
        move_object(cyhead, cyberman);
    }
}

ONE_EXIT("players/boltar/lv2/level2room4.c", "west",
        "The cyber room",
 "This room contains more of the same sort of junk as the last room did,\n" +
 "however, some of it appears to be making noise.\n", 1)
