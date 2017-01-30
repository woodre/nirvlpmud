#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset(){
int i;
object armor, rider, gem, berries;
	if(!present("berries")){
	i=0;
	while(i<3){
	i += 1;
	berries=clone_object("players/ultramagnus/berries.c");
	move_object(berries, this_object());
	}
}
	if(!present("rider")){
	i = 0;
	while(i<2){
	i+=1;
		rider=clone_object("players/ultramagnus/rider.c");
              call_other(rider, "set_aggressive", 1);
              call_other(rider, "set_a_chat_chance", 35);
              call_other(rider, "load_a_chat",
                            "The Dark Rider goes through your pockets...\n");
              call_other(rider, "load_a_chat",
                            "Dark Rider says: Where is the Ring-Bearer...??!!\n");
              call_other(rider, "load_a_chat",
                            "Dark Rider Reaches for your Soul...!!!\n");
		move_object(rider, this_object());
}
		gem=clone_object("players/ultramagnus/bdiamond.c");
		move_object(gem, rider);
              gem=clone_object("players/ultramagnus/rdiamond.c");
              move_object(gem, rider);
/* This armor shifting to Balrog -Snow 3/00
              armor=clone_object("players/ultramagnus/breastplate.c");
              move_object(armor, rider);
*/
	}
}
ONE_EXIT("players/ultramagnus/bforest5.c", "down",
	"Blue Tree",
       "This is a cheerful area...it seems....\n" +
	"The Berries in this tree grow in abundance\n" +
	"There are berries everywhere it seems.\n", 1)
