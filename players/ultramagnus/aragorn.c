#include "room.h"



#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
object weapon;
object Aragorn;
if (!Aragorn || !living(Aragorn)) {
Aragorn = clone_object("obj/monster");
call_other(Aragorn, "set_name", "aragorn");
call_other(Aragorn, "set_hp", 500);
call_other(Aragorn, "set_wc", 30);
call_other(Aragorn, "set_whimpy", 1);
call_other(Aragorn, "set_ac", 17);
call_other(Aragorn, "set_al", 500000);
call_other(Aragorn, "set_short", "Aragorn son of Arathorn, direct decendent of Isildur Elendil");
call_other(Aragorn, "set_long",
"Aragorn is one of the direct sons of Isidur Elendil.  Aragorn \n"+

"is the rightful heir to the throne, and the bearer of Isildur's \n"+
"sword which was broken and reforged by Elrond's elves.  The \n"+
"bearer of this sword is a very powerful person, somewhat like \n"+
"Aragorn.  Should you attack Aragorn, be prepared for a battle, \n"+
"the blood of the men of Numenor runs stong with in him.\n");
call_other(Aragorn, "set_level", 20);
move_object(Aragorn, this_object());
weapon=clone_object("obj/weapon");
call_other(weapon, "set_name", "Anduril");
call_other(weapon, "set_alt_name", "sword");
call_other(weapon, "set_long", "Sword of Anduril, an excellant weapon\n");
call_other(weapon,"set_class", 18);
call_other(weapon, "set_save_flag", 0);
call_other(weapon, "set_value", 9000);
call_other(weapon, "set_weight", 2);
move_object(weapon, Aragorn);
call_other(Aragorn, "init_command", "wield Anduril");
    }
}

ONE_EXIT("players/turk/orcs2", "west",

"Aragorn",
"As you enter the room you notice that you are in the presence of a \n"+
"powerful being.  Aragorn is one of the most powerful people in the \n"+
"world, both mentally and physically.  He is a healer, a King to be,\n"+
"an excellant warrior, and a counselor.  All around, he is a \n"+
"bad person not to have on your side.\n", 1)
