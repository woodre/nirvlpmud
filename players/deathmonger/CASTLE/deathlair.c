
#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
object death, sword, money;
extra_reset() {
if (!death || !living(death)) {
     death = clone_object("obj/monster");
     call_other(death, "set_name", "Crimson Death");
     call_other(death, "set_alias" ,"death");
     call_other(death, "set_level", 16);
     call_other(death, "set_hp", 400);
     call_other(death, "set_ac", 13);
     call_other(death, "set_wc", 22);
     call_other(death, "set_chance", 50);
     call_other(death, "set_spell_dam", 26);
     call_other(death, "set_spell_mess1", "The Crimson Death sucks a victim"+
               " dry.\n");
     call_other(death, "set_spell_mess2", "The Crimson Death sucks blood from"+
               " your veins!\n");
     call_other(death, "set_aggressive", 1);
     call_other(death, "set_long", "The Crimson Death is an immaterial cloud-"+
               "like creature that appears as a mist.\n"+
               "When it is fully gorged with human blood, the cloud takes\n"+
               "on a crimson hue; from this it gets its name.  It is thought\n"+
               "by some that Crimson Deaths are the dead spirits of vampires,\n"+
               "but their origin is not known for certain.\n");
     move_object(death, this_object());

     sword = clone_object("obj/weapon");
     call_other(sword, "set_name", "sabre");
     call_other(sword, "set_alias", "sword");
     call_other(sword, "set_class", 15);
     call_other(sword, "set_weight", 2);
     call_other(sword, "set_value", 800);
     call_other(sword, "set_short", "Crimson Sabre");
     move_object(sword, death);

     money = clone_object("obj/money");
     call_other(money, "set_money", random(300));
     move_object(money, death);
}
}
ONE_EXIT("players/deathmonger/main3", "east",
         "Crimson Death lair",
         "You enter a lair of some sort.  There is a crimson colored mist\n"+
         "surrounding the area.  There doesn't appear to be anything here\n",
         0)
