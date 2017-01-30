#include "/players/eurale/closed/ansi.h"

inherit "obj/armor";

reset(arg) {
set_name("shield");
set_alias("towershield");
set_short("P"+YEL+"latinum "+NORM+"{"+HIY+"+"+NORM+"} T"+YEL+"owershield"+NORM);
set_long(
  "A huge, platinum towershield with the Royal Crest on its face.  It covers\n"+
  "from neck to knees providing great protection.\n");

set_ac(2);
set_type("shield");
set_weight(3);
set_value(1700);
/*
set_save_flag();
*/
}
