#include "std.h"
object sex, money;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
if (!sex || !living(sex)) {
        sex = clone_object("obj/monster.talk");
        call_other(sex, "set_name", "sex"); 
call_other(sex, "set_level", 18);  
 
        call_other(sex, "set_whimpy", 150);
        call_other(sex, "set_al", 250);
        call_other(sex, "set_ac", 15); 
        call_other(sex, "set_wc", 26);
call_other(sex, "set_short", "A Sex Maniac");
        call_other(sex, "set_long",
                "Mr. Sex Maniac.  Kill this sex machine\n");
    call_other(sex, "set_chat_chance", 40);
    call_other(sex, "load_chat",
        "SEX says:  Hi Hornballs!  You were looking for me, werent you?\n");
       call_other(sex, "load_chat",
        "Sex says:  Here I am.  Make my day!\n");
        call_other(sex, "load_chat",
        "Sex says: Chop my prick!\n");
         call_other(sex, "set_a_chat_chance", 30);
        call_other(sex, "load_a_chat",
        "sex says: Hey asshole!  You are asking for it!\n");
	        money = clone_object("obj/money");
        call_other(money, "set_money", 500+random(1000));
        move_object(money, sex);                                         
        call_other(sex, "load_a_chat", "Sex screams in pain.\n");
        move_object(sex, this_object());
   }
}
 
ONE_EXIT("players/airwoman/CASTLE/rm2n", "west",
        "A room with a sex.",
        "So here's SEX!  Thats what you were looking for, right?\n",
         1)
                         
