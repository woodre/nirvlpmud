#include "room.h"
object tarzan, cheetah, brains;
object bully;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
if (!present("tarzan")) {
        tarzan = clone_object("obj/monster");
        call_other(tarzan, "set_name", "tarzan");
        call_other(tarzan, "set_level", 12);
        call_other(tarzan, "set_hp", 180);
        call_other(tarzan, "set_al", 500);
        call_other(tarzan, "set_short", "Tarzan, Lord of the Apes");
        call_other(tarzan, "set_long", "This is the mighty Tarzan.\n");
        call_other(tarzan, "set_wc", 16);
        call_other(tarzan, "set_ac", 9);
        move_object(tarzan, this_object());
}
if (!present("cheetah")) {
        cheetah = clone_object("obj/monster");
        call_other(cheetah, "set_name", "cheetah");
        call_other(cheetah, "set_level", 5);
        call_other(cheetah, "set_hp", 75);
        call_other(cheetah, "set_al", 100);
        call_other(cheetah, "set_short", "Cheetah, the chimpanzee");
        call_other(cheetah, "set_wc", 9);
        call_other(cheetah, "set_ac", 5);
        call_other(cheetah, "set_long", "Why did they name this chimp\n"+
        "Cheetah, anyway?\n");
     
        brains = clone_object("obj/treasure");
         call_other(brains, "set_id", "brains");
        call_other(brains, "set_value", 200);
        call_other(brains, "set_short", "The brains of Cheetah");
        call_other(brains, "set_long", "These monkey brains are a delicacy.\n");
        call_other(brains, "set_weight", 1);
         move_object(brains, cheetah);
         move_object(cheetah, this_object());
/*
if(!present("inspector", find_object("room/ravine"))){
     bully = clone_object("players/deathmonger/MAGIC/bully");
     move_object(bully, "room/ravine");
}
*/
}
}
TWO_EXIT("players/deathmonger/main6", "west",
         "players/deathmonger/CASTLE/coatl","south",
         "Tarzan's treehouse",
         "This is Tarzan's home.  This tree-top estate is a great\n"+
         "treehouse, with vines in all directions for Tarzan's transporta-\n"+
         "tion.  Jane is away for now, but she'll be back.\n",   1)


