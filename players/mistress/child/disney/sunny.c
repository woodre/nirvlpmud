#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
   if(!present("sunny")) {\
     object sunny;\
     sunny = clone_object("obj/torch");\
     call_other(sunny, "set_name", "sunflower");\
     call_other(sunny, "set_fuel", 5000);\
     call_other(sunny, "set_weight", 1);\
     call_other(sunny, "set_value", 150);\
     move_object(sunny, "players/mistress/child/disney/sunny");\
     } \

ONE_EXIT("players/mistress/child/disney/room3a","north",
   "Sunny Sunflower",
   "\nLarge sunflowers shine their happy faces down at you.  They seem\n" +
   "to create their own light, because though they crowd around and shut\n" +
   "out the natural sunlight, you feel like you are basking in the warmest\n" +
   "of sunshine.  If you find one, you might even try lighting it.\n",1)
