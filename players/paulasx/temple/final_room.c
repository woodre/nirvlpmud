
#include "std.h"

int found;
    object chalice, benju;

#undef EXTRA_RESET
#define EXTRA_RESET \
    fix_benju();

fix_benju() {
    if (!benju || !living (benju)) {
        benju = clone_object ("obj/monster");
        call_other (benju, "set_name", "benju");
        call_other (benju, "set_alias", "benju matsutomo");
        call_other (benju, "set_race", "benju");
        call_other (benju, "set_level", 25); 
        call_other (benju, "set_hp", 700);
        call_other (benju, "set_ep", 3500000); 
        call_other (benju, "set_al", -500);
        call_other (benju, "set_short", "Benju Matsutomo");
        call_other (benju, "set_long",
                "The keeper of evil within the Temple of Bishamon.\n");
        call_other (benju, "set_wc", 35);
        call_other (benju, "set_ac", 12);
        call_other (benju, "set_aggressive", 1);
/*
        call_other (benju, "set_whimpy", 1);
*/

        chalice = clone_object ("obj/treasure");
        call_other (chalice, "set_id", "chalice");
        call_other (chalice, "set_alias", "gold chalice");
        call_other (chalice, "set_short", "A gold chalice");
        call_other (chalice, "set_value", 12545);

     move_object (benju, this_object());
    move_object (chalice, benju);
        }
}

ONE_EXIT ("players/paulasx/temple/quest_room", "north",
          "Benju's Lair",
          "You are in the lair of Benju, Lord of Darkness.\n" +
          "Benju has been waiting for you for a long time.  He has\n" +
          "watched you move throughout his Temple, and has\n" +
          "waited patiently for this day.  This shall be the end\n" +
          "of your life!\n\n", 1) 
