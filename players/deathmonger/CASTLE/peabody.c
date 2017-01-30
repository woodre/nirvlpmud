#include "room.h"
object rabbit, sherman;



#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
if (!rabbit || !living(rabbit)) {
     rabbit = clone_object("obj/monster");
     call_other(rabbit, "set_name", "peabody");
     call_other(rabbit, "set_alias", "mr. peabody");
     call_other(rabbit, "set_al", 150);
     call_other(rabbit, "set_hp", 400);
     call_other(rabbit, "set_level", 16);
     call_other(rabbit, "set_race", "dog");
     call_other(rabbit, "set_ac", 13);
     call_other(rabbit, "set_wc", 22);
     call_other(rabbit, "set_short", "Mr. Peabody");
     call_other(rabbit, "set_long", "This world famous dog is a brilliant\n"+
               "time traveler, and general philosophizer.\n");
     

     call_other(rabbit, "set_chat_chance", 60);
     call_other(rabbit, "load_chat", "Mr. Peabody says, 'Never fear, my"+
     " dear boy Sherman.\n");
     call_other(rabbit, "load_chat", "Mr. Peabody says, 'Let's set the"+
     " Way-Back Machine to the year...'\n");
     call_other(rabbit, "load_chat", "You too can use the Way-Back Machine.\n");
     call_other(rabbit, "set_a_chat_chance", 75);
     call_other(rabbit, "load_a_chat", "Mr. Peabody says, 'This situation"+
     " calls for extreme measures, my dear boy.'\n");
     call_other(rabbit, "load_a_chat", "Mr. Peabody says, 'We need a miracle"+
     " here.'");
     call_other(rabbit, "load_a_chat", "Mr. Peabody says, 'I have a plan.'\n");
     move_object(rabbit, this_object());
}
if (!sherman || !living(sherman)) {
     sherman = clone_object("obj/monster");
     call_other(sherman, "set_name", "sherman");
     call_other(sherman, "set_level", 10);
     call_other(sherman, "set_al", 150);
     call_other(sherman, "set_ac", 8);
     call_other(sherman, "set_wc", 14);
     call_other(sherman, "set_short", "and His Boy, Sherman");
     call_other(sherman, "set_long", "This is Mr. Peabody's sidekick,\n"+
     "Sherman.  He's studying the Way-Back Machine intensely.\n");
     call_other(sherman, "set_chat_chance", 60);
     call_other(sherman, "load_chat", "Sherman says, 'Gee, Mr. Peabody,\n"+
     "you're smart!\n");
     call_other(sherman, "load_chat", "Sherman beams at Mr. Peabody"+
     " worshipfully.\n");
     call_other(sherman, "load_chat", "Sherman says, 'Where are we going?'\n");
     call_other(sherman, "set_a_chat_chance", 75);
     call_other(sherman, "load_a_chat", "Sherman says, 'Gee, we're in"+
     "trouble now, Mr. Peabody!\n");
     call_other(sherman, "load_a_chat", "Sherman says, 'How will we get out"+
     "of this one?\n");
     move_object(sherman, this_object());
}
}

TWO_EXIT("players/deathmonger/west_hall2", "south",
         "players/deathmonger/CASTLE/wayback", "east",
         "Mr. Peabody and his boy, Sherman",
         "In front of you are Mr. Peabody and his boy, Sherman.  They look\n"+
         "like they're getting ready to go on yet another time journey.\n",
1)
