
#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
     object dracolich, sword;
     if(!present("dracolich")){
     dracolich = clone_object("obj/monster");
     dracolich->set_name("dracolich");
     dracolich->set_alias("dragon");
     dracolich->set_alias("fassoon");
     dracolich->set_level(23);
     dracolich->set_hp(760);
     dracolich->set_wc(20);
     dracolich->set_ac(12);
     dracolich->set_chance(37);
     dracolich->set_spell_dam(35);
     call_other(dracolich, "set_spell_mess1",
       "The Dracolich breathes fire!");
     call_other(dracolich, "set_spell_mess1",
       "The Dracolich casts a lightning bolt!");
     call_other(dracolich, "set_spell_mess2",
       "You are charred by the searing heat of the Dracolich's breath!\n");
     call_other(dracolich, "set_spell_mess2",
       "The Dracolich crushes you with a lightning bolt!\n");
     dracolich->set_short("Fassoon, an Abyssinian Red Dracolich");
     call_other(dracolich, "set_long", 
     "Fassoon is an unusually large dracolich.  Dracoliches are dragons\n"+
     "who have become liches.   Fassoon is huge for two reasons:  First,\n"+
     "red dragons are the largest of the genus, and second, the Abyssinian\n"+
     "subspecies of dragon is known for its monstrous proportions.  He is a\n"+
     "very difficult opponent\n");
     sword = clone_object("players/deathmonger/WEAPONS/vampsword");
     move_object(sword, dracolich);
     move_object(dracolich, this_object());
}
}


TWO_EXIT("players/deathmonger/CASTLE/fortress/lich","east",
         "players/deathmonger/CASTLE/fortress/tower1", "up",
         "Lair of the Dracolich",
         "You come to a huge room with a very high ceiling.  This is the\n"+
         "lair of a dracolich.  This dracolich is exceptionally large.\n",
1)
