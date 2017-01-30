#include "room.h"
object wiz, ring;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if (!wiz || !living(wiz)) {
     wiz = clone_object("obj/monster");
     call_other(wiz, "set_name", "wicked witch");
     call_other(wiz, "set_alias", "witch");
     call_other(wiz, "set_level", 21);
     call_other(wiz, "set_al", -350);
     call_other(wiz,"set_short", "The Wicked Witch of the West");
     call_other(wiz, "set_long", "The cruel Wicked Witch of the West.\n");
     call_other(wiz, "set_chance", 35);
     call_other(wiz, "set_spell_dam", 19);
     call_other(wiz, "set_spell_mess1", "The Witch casts a fireball.\n");
     call_other(wiz, "set_spell_mess2", "How about a little fire, scarecrow?"+
" ");
     call_other(wiz, "set_wc", 32);
     call_other(wiz, "set_ac", 17);
     call_other(wiz, "set_hp", 550);
     call_other(wiz, "set_chat_chance", 65);
     call_other(wiz, "load_chat", "I'll get you, my pretty, and your little\n"+
                " dog, too!\n");
     call_other(wiz, "set_a_chat_chance", 65);
     call_other(wiz, "load_a_chat", "Witch says, 'You have this long to"+
                " live\n");
     move_object(wiz, this_object());
     ring = clone_object("obj/armor");
     call_other(ring, "set_name", "hat");
     call_other(ring, "set_short", "Wicked Witch of the West's Hat");
     call_other(ring, "set_ac", 1);
     call_other(ring, "set_type", "helmet");
     call_other(ring, "set_value", 1000);
     move_object(ring, wiz);
}
}
ONE_EXIT("players/deathmonger/poppies", "east",
         "The Castle of the Wicked Witch of the West",
         "The evil castle of the Wicked Witch of the West.\n", 
1)
