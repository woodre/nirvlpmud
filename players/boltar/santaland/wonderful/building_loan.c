#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset()
{
    object townp, money, hamr;
    int i;

    i = 0;
    if (!present("friend")) {
	while(i<8) {
	    i += 1;
	    townp = clone_object("obj/monster");
	call_other(townp, "set_name", "friend");
if (i == 8 && !present("billy"))
    call_other(townp, "set_name", "billy");
	call_other(townp, "set_hp", 50);
call_other(townp, "set_ac", 3);
	call_other(townp, "set_wc", 4);
	call_other(townp, "set_al", 100);
	call_other(townp, "set_short", "One of George's friends");
if (i == 8 && !present("billy"))
   call_other(townp, "set_short", "Uncle Billy");
	call_other(townp, "set_long",
  "One of the many people george has helped in Bedford falls.\n");
 if (i == 8 && !present("billy"))
  call_other(townp, "set_long", "George's uncle Billy who lost the money.\n");
	call_other(townp, "set_aggressive", 0);
call_other(townp, "set_level", 2);
if (i == 7 && !present("examiner")){
  call_other(townp, "set_name","examiner");
  call_other(townp, "set_short", "The Bank Examiner");
  call_other(townp, "set_long", "He's here to check the books.\n");
  }
	    move_object(townp, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(100));
        move_object(money, townp);
	}
    }
}

TWO_EXIT("players/boltar/santaland/wonderful/george_office.c", "east",
    "players/boltar/santaland/wonderful/main_st.c", "west",
 "The Bailey Building and Loan",
  "You have entered the Bailey Building and Loan. It was started by George's\n"+
  "father and uncle Billy.  George runs the business now, and has to fend off\n"+
 "Potter at every turn. The tellers are in a cage in the center where you can't\n"+
"get in. There is an office to the east.\n", 1)
