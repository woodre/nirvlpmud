#include "/players/dragnar/guild/defs/def.h"
equil() {
        int amount;
        amount = (usp + uhp) / 2;
        if(uhp < amount) {
        this_player()->heal_self(amount - uhp);
        this_player()->add_spell_point(-(usp - amount));
        write("You use some of your magic to become stronger.\n");
        return 1;
        }
        if(uhp > amount) {
        this_player()->heal_self(-(uhp - amount));
        this_player()->add_spell_point(amount - usp);
        write("You use some of your strength to increase your magic.\n");
        return 1;
        }
        if(uhp == amount) {
        write("Your magic and strength are already equil.\n");
        return 1;
        }
}
