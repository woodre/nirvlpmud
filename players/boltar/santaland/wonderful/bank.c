#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset()
{
    object townp, money, hamr;
    int i;

    i = 0;
    if (!present("visitor")) {
	while(i<8) {
	    i += 1;
	    townp = clone_object("obj/monster");
	call_other(townp, "set_name", "visitor");
if (i == 8) 
    call_other(townp, "set_name", "teller");
	call_other(townp, "set_hp", 50);
call_other(townp, "set_ac", 3);
	call_other(townp, "set_wc", 4);
	call_other(townp, "set_al", 100);
	call_other(townp, "set_short", "A bank visitor");
if (i == 8)
   call_other(townp, "set_short", "A bank teller");
	call_other(townp, "set_long",
   "A visitor to the Bedford falls bank.\n");
if (i==8) 
   call_other(townp, "set_long", "The bank's on duty teller.\n");
	call_other(townp, "set_aggressive", 0);
call_other(townp, "set_level", 2);
	    move_object(townp, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(100));
        move_object(money, townp);
	}
    }
}

TWO_EXIT("players/boltar/santaland/wonderful/potter_office.c", "south",
    "players/boltar/santaland/wonderful/main_st.c", "east",
 "The Bedford Falls Bank",
 "You have entered the Bedford Falls bank, which of course is owned by Mr.\n"+
 "Potter. There is a large cage to the west, but you cant get through it, Mr.\n"+
 "Potter doesn't take any risks with his money. There is a table for writing\n"+
 "out deposit and withdrawal slips in the center of the room. There is a door\n"+
"to the south.\n", 1)
