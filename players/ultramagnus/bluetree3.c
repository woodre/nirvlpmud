#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset(){
int i;
object elf, gem, berries;
	if(!present("berries")){
	i=0;
	while(i<3){
	i += 1;
	berries=clone_object("players/ultramagnus/berries.c");
	move_object(berries, this_object());
	}
	}
	if(!present("elf")){
		elf=clone_object("players/ultramagnus/belf.c");
		move_object(elf, this_object());
		gem=clone_object("players/ultramagnus/bdiamond.c");
		move_object(gem, elf);
	}
}
ONE_EXIT("players/ultramagnus/bforest3.c", "down",
	"Blue Tree",
	"The Berries in this tree grow in abundance\n" +
	"There are berries everywhere it seems.\n", 1)
