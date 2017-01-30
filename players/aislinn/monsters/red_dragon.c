#include "std.h"
 
object dragon;
 
extra_reset() {
    object treasure;
    if (!dragon || !living(dragon)) {
        dragon = clone_object("obj/monster");
        call_other(dragon, "set_name", "dragon");
        call_other(dragon, "set_level", 19);
        call_other(dragon, "set_hp", 250);
        call_other(dragon, "set_short", "A fierce red dragon");
        call_other(dragon, "set_wc", 22);
        call_other(dragon, "set_ac", 5);
        call_other(dragon, "set_al", -900);
        call_other(dragon, "set_aggressive", 1);
        call_other(dragon, "set_chance",25);
        call_other(dragon, "set_spell_mess1",
                   "The dragon envelopes you in flames!");
        call_other(dragon, "set_spell_mess2",
                   "The dragon roars and lets out a jet of flame.");
        call_other(dragon, "set_spell_dam",32);
        move_object(dragon, this_object());
        treasure = clone_object("obj/treasure");
        call_other(treasure, "set_id", "sceptre");
        call_other(treasure, "set_short", "A sparkling jewelled sceptre");
        call_other(treasure, "set_weight", 4);
        call_other(treasure, "set_value", 3500);
        move_object(treasure, dragon);
    }
}
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
