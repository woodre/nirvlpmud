#include "std.h"

int i,count;
object dalek;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object creature;
    i=0;
    if (!present("dalek")) {
    while(i<3) {
    i += 1;
	dalek = clone_object("obj/monster");
call_other(dalek, "set_name", "dalek");
call_other(dalek, "set_short", "A grey dalek"); 
call_other(dalek, "set_object", this_object());
	call_other(dalek, "set_hp", 350);
call_other(dalek, "set_ac", 9);
	call_other(dalek, "set_wc", 16);
	call_other(dalek, "set_al", -1000);
call_other(dalek, "set_whimpy");
	call_other(dalek, "set_long",
   "Before you, you see a mark I dalek. Grey with black highlights.\n");
	call_other(dalek, "set_aggressive", 1);
call_other(dalek, "set_level", 14);
	call_other(dalek, "set_spell_mess1",
   "The Dalek fires this weapon.");
	call_other(dalek, "set_spell_mess2",
   "The dalek fires his weapon at you! OUCH!!");
	call_other(dalek, "set_chance", 25);
move_object(dalek, this_object());
call_other(dalek, "set_spell_dam", 12);
call_other(dalek, "set_a_chat_chance", 40);
call_other(dalek, "load_a_chat", "We have only been delayed not defeated!! The Daleks are never defeated!!!\n");
call_other(dalek, "load_a_chat", "Dalek says: exterminate!! exterminate!!\n");
call_other(dalek, "load_a_chat", "Dalek says: My vision is impared, I cannot see!!!\n");
	money = clone_object("obj/money");
        call_other(money, "set_money", random(1000));
        move_object(money, dalek);
creature = clone_object("obj/treasure");
        call_other(creature, "set_id", "creature");
        call_other(creature, "set_short", "A dalek slime creature");
        call_other(creature, "set_value", 300);
        call_other(creature, "set_long", "This is the slime from which the daleks where made..");
        call_other(creature, "set_weight", 2);
        move_object(creature, dalek);
    }
}
}

TWO_EXIT("players/boltar/lv2/davrosroom.c", "west",
 "players/boltar/lv2/drenter.c", "south",
        "Dalek room",
 "This room is filled with machines and other junk, no telling where this all\n" +
 "leads.\n", 1)
