#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset(){
int i;
object elf, gem, apple;
	if(!present("elf")){
	i=0;
	while(i<3){
	i += 1;
	apple=clone_object("players/ultramagnus/apple.c");
       elf=clone_object("players/ultramagnus/relf.c");
       gem=clone_object("players/ultramagnus/rdiamond.c");
       move_object(elf, this_object());
       move_object(apple, elf);
       move_object(gem, elf);
	}
	}
}
ONE_EXIT("players/ultramagnus/rforest5.c", "down",
	"Red Tree",
       "This is a cheerful area...it seems....\n" +
	"The Apples in this tree grow in abundance\n" +
	"There are apples everywhere it seems.\n", 1)
