#include "room.h"
object lily, money;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
int i;
i = 0;
if(!present("lilliputian")) {
while(i<13) {
i +=1;
	lily =clone_object("obj/monster");
	call_other (lily, "set_name", "lilliputian");
	call_other (lily, "set_level", 2);
	call_other (lily, "set_hp", 50);
	call_other (lily, "set_wc", 2);
	call_other (lily, "set_al", 200);
	call_other (lily, "set_short", "An annoying lilliputian");
	call_other (lily, "set_long",
	"A being approx. 2 in. tall.  EASY KILL!\n");

	move_object (lily, this_object());
	money = clone_object("obj/money");
	call_other(money, "set_money", random(80));
	move_object(money, lily);
}
}
}
TWO_EXIT ("players/airwoman/CASTLE/rm2e", "west",
	"players/airwoman/CASTLE/rm4e", "east",
	"A strange place.",
"Somehow you have encountered the people of Lilliput.\n"+
"ALL you can see are these annoying LILLIPUTIANS that seem to bother your feet!!!\n",
1)
