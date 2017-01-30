#include <ansi.h>
inherit "obj/treasure";
drop() { return 1; }
reset(arg) {
if(arg) return;
set_id("eye");
set_alias("eye");
set_short(BOLD+RED+"Dragon "+YELLOW+"Eye "+RED+"Ring"+NORM+" (worn)");
set_long(
"A black ring forged from the hellish fires of the Underworld\n"+
"with an ancient stone set within called "+BOLD+YELLOW+"Eye "+RED+"of the Dragon"+NORM+".\n"+
NORM+"Magically the eye shines with an eerie gold light, blinking\n"+
"and turning as though it was alive. Strange markings are\n"+
"enscribed in the inner circumference of the ring.\n");
set_value(0);
set_weight(0);
}

init() {
     add_action("read","read");
}

read(str) {
     if(str != "markings") {
          write("Read what?\n");
          return 1;
     }
     else {
          write("The markings read:\n");
          write("Forged in the fiery pits of hell by "+BOLD+RED+"P A I N"+NORM+".\n");
          return 1;
     }
}

query_auto_load() { return "/players/pain/closed/items/diabla_ring.c:";}
