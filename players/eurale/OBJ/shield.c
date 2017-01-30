#include "/players/eurale/closed/ansi.h"

inherit "obj/armor";

reset(arg) {
set_name("shield");
set_alias("towershield");
set_short(HIC+"skyblue towershield"+NORM);
set_long(
  "A large, skyblue towershield with gold gilded edges that covers\n"+
  "from neck to knees providing great protection.\n");

set_ac(1);
set_type("shield");
set_weight(3);
set_value(1700);
}
