#include "/players/francesco/univ/ansi.h"
inherit "obj/treasure.c";

int current_page;

reset(arg)
{
    if(arg) return;
    current_page = 0;
}

short() { return "A coloured flier"; }

long(str) {
    write(RED+"The flier\n"+
          GRN+"The flier\n"+
          YEL+"The flier\n"+
          BLU+"The flier\n"+
          MAG+"The flier\n"+
          CYN+"The flier\n"+
          WHT+"The flier\n"+
          HIR+"The flier\n"+
          HIG+"The flier\n"+
          HIY+"The flier\n"+
          HIB+"The flier\n"+
          HIM+"The flier\n"+
          HIC+"The flier\n"+
          HIW+"The flier\n"+
          RED+"The flier\n"+
          RED+"The flier\n"+
          RED+"The flier\n"+
          RED+"The flier\n"+
          RED+"The flier\n"+
          RED+"The flier\n"+
          RED+"The flier\n"+
          NORM+"The flier\n");
	return;
    }
    


id(str) { return str == "flier" ; }


