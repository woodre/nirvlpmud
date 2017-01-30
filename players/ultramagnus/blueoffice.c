#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
object vest,gem, sack, elf;
int i;
       if(!present("elf")){
       elf=clone_object("obj/monster.c");
       call_other(elf, "set_name", "elf");
       call_other(elf, "set_alias", "elf");
       call_other(elf, "set_level", 12);
       call_other(elf, "set_short", "A Chubby  Elf in a Blue Vest");
       call_other(elf, "set_long",
	"A Chubby looking Elf in a Blue Vest.\n" +
	"He seems to be in charge here.\n");
	call_other(elf, "set_wc", 15);
  call_other(elf,"set_ac",8);
	call_other(elf, "set_hp", 200);
	call_other(elf, "set_al", 150);
	call_other(elf, "set_level", 10);
	call_other(elf, "set_aggressive", 0);
	call_other(elf, "set_chat_chance", 35);
	call_other(elf, "load_chat",
		"Elf says: Hello There! Want a Job?\n");
	call_other(elf, "load_chat",
		"Elf says: You will be paid well!!!\n");
	call_other(elf, "load_chat",
		"Elf says: Come now! Make up your mind! I have others waiting!\n");
	call_other(elf, "set_a_chat_chance", 35);
	call_other(elf, "load_a_chat",
		"Elf says: I may be a bit aged but I can STILL handle the likes of YOU!!!\n");
	call_other(elf, "load_a_chat",
		"Elf says: Why can't you make an honest dollar foul one??!!\n");
	move_object(elf, this_object());
	}
	sack=clone_object("players/ultramagnus/bsack.c");
	i=0;
	while(i<2){
i += 1;
	gem=clone_object("players/ultramagnus/bdiamond.c");
	move_object(gem, sack);
	}
	move_object(sack, elf);
       vest=clone_object("players/ultramagnus/vest.c");
       move_object(vest, elf);
}
ONE_EXIT("players/ultramagnus/treehut.c", "out",
        "Blue Office",
        "You have entered the Blue Office.  There is a small desk and chair\n" +
        "in the middle of the room.  The furniture is brown with Blue coloring\n" +
        "as an outline.  You have to bend your knees and keep your head down\n" +
        "so that you can stand.\n", 1)
