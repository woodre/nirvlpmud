
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init(){
     add_action("search","search");
     add_action("south", "south");
}

search(){
     write("You notice a little tunnel leading south.\n");
     return 1;
}
south(){
     this_player()->move_player("south#players/deathmonger/UNDERDARK/svirf/entrance");
     return 1;
}

TWO_EXIT("players/deathmonger/UNDERDARK/tunnel12", "east",
         "players/deathmonger/UNDERDARK/tunnel14", "west",
         "Underdark tunnel",
         "Suddenly, everythiing grows quiet here.  No signs of life,\n"+
         "nothing.  The  cavern looks like there's been no activity\n"+
         "here for ages.  Perhaps you should take a closer look.\n", 0) 
