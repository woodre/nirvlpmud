
#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
object death, sword, money;
extra_reset() {
if (!death || !living(death)) {
     death = clone_object("obj/monster");
     call_other(death, "set_name", "Coatl");
     call_other(death, "set_alias","coatl");
     call_other(death, "set_level", 16);
     call_other(death, "set_hp", 400);
      call_other(death, "set_ac", 13);
     call_other(death, "set_wc", 22);
     call_other(death, "set_chance", 50);
     call_other(death, "set_spell_dam", 26);
     call_other(death, "set_spell_mess1","The Coatl casts a fireball.\n");
     call_other(death, "set_spell_mess2","You feel the fury of the Coatl's"+
               " fireball.\n");
     call_other(death, "set_long", "The Coatl is a mythical creature \n"+
                "immortalized in the crest of the medical emblem.  It is\n"+
                "a snake with wings, in short, and is a very good and intel-\n"+
                "ligent creature.  Some socities worship the coatl.\n");
     move_object(death, this_object());

     sword = clone_object("obj/weapon");
     call_other(sword, "set_name", "spring sword");
     call_other(sword, "set_alias", "sword");
     call_other(sword, "set_class", 15);
     call_other(sword, "set_weight", 2);
     call_other(sword, "set_value", 800);
     call_other(sword, "set_short", "A glowing spring sword");
     call_other(sword, "set_long","The spring sword is a whip-like\n"+
               "sword that has several flexible blades attached to a \n"+
               "central handle.  The weapon is wielded by whirling the \n"+
               "blades around and slicing the victim with the whirling\n"+
               "blades.\n");
     move_object(sword, death);

     money = clone_object("obj/money");
     call_other(money, "set_money", random(300));
     move_object(money, death);
}
}
TWO_EXIT("players/deathmonger/main5", "west",
         "players/deathmonger/CASTLE/tarzan_room","north",
         "Home of the Coatl",
         "You enter a beatiful section of the jungle.  A waterfall crashes\n"+
         "beside you.  Many animals frolic about in the peaceful scene.\n",
         1)
