#include "room.h"
object tarzan, cheetah, skin, brains;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
if (!tarzan || !living(tarzan)) {
        tarzan = clone_object("obj/monster");
        call_other(tarzan, "set_name", "george");
        call_other(tarzan, "set_level", 12);
        call_other(tarzan, "set_hp", 200);
        call_other(tarzan, "set_al", 500);
        call_other(tarzan, "set_short", "George of the Jungle");
        call_other(tarzan, "set_long", "This is the powerful\n"+
                  "George of the Jungle.  He almost looks like a cartoon\n"+
                  "character.\n");
        call_other(tarzan, "set_wc", 16);
        call_other(tarzan, "set_ac", 9);
        move_object(tarzan, this_object());
}
if (!cheetah || !living(cheetah)) {
        cheetah = clone_object("obj/monster");
        call_other(cheetah, "set_name", "ape");
        call_other(cheetah, "set_level", 5);
        call_other(cheetah, "set_hp", 75);
        call_other(cheetah, "set_al", 100);
                call_other(cheetah, "set_short", "An ape named Ape");
        call_other(cheetah, "set_wc", 9);
        call_other(cheetah, "set_ac", 5);
        call_other(cheetah, "set_long", "George's sidekick, Ape.\n");
        skin = clone_object("obj/treasure");
        call_other(skin, "set_id", "tree");
        call_other(skin, "set_value", 700);
        call_other(skin, "set_alias", "leopard skin");
        call_other(skin, "set_weight", 1);
        call_other(skin, "set_short", "A tree skewered on George's nose");
        call_other(skin, "set_long", "George, without fail, always\n"+
                   "runs into a tree whenever he swings on a vine.\n");
        move_object(skin, tarzan);
        brains = clone_object("obj/treasure");
        call_other(brains, "set_id", "calculator");
        call_other(brains, "set_value", 200);
        call_other(brains, "set_short", "Ape's calculator");
        call_other(brains, "set_long", "Ape, being an intellectual,\n"+
                  "never leaves home without his calculator.\n");
        call_other(brains, "set_weight", 1);
         move_object(brains, cheetah);
         move_object(tarzan, this_object());
         move_object(cheetah, this_object());
}
}
ONE_EXIT("players/deathmonger/main6","east",
         "George's Hideout",
         "You have stumbled upon George of the Jungle's home.  He's a very\n"+
         "friendly, if absent minded, kind of guy.  He has a habit of\n"+
         "smashing into trees when he gets on his vine.\n", 1)

