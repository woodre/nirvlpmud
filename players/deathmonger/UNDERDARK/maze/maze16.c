
#include "std.h"

int search;
reset(arg){
     if(!arg){
     set_light(1);
     }
}

init(){
      add_action("east","east");
     add_action("west","west");
     add_action("south","south");
     add_action("search","search");
}

search(){
     write("You find a little tunnel leading south.\n");
     search = 1;
     return 1;
}

east(){
this_player()->move_player("east#players/deathmonger/UNDERDARK/maze/maze15");
return 1;
}

west(){
     write("You enter Baphomet's magical field only to end up in the church!\n");
this_player()->move_player("west#room/church");
return 1;
}

south(){
    if(search == 1){
this_player()->move_player("south#players/deathmonger/UNDERDARK/maze/baph");
return 1;
}
write("What?\n");
return 1;
}
short(){ return "End of what wasn't a maze"; }

long(){
write("You seem to have reached the end of what would have been a maze\n");
write("if you had been in a maze.  There are large piles of bones strewn\n");
write("about this tunnel.  The exit to the west shimmers in magical radiance.\n");
write("You can hear growls to the west.\n");
write("There are two obvious exits: east and west.\n");
}
