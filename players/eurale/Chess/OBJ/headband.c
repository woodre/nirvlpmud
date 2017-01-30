#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("headband");
set_short(HIY+"Pl"+HIR+"*"+HIY+"ati"+HIR+"*"+HIY+"num"+
  HIR+"*"+HIY+"Hea"+HIR+"*"+HIY+"dba"+HIR+"*"+HIY+"nd"+NORM);
set_long(
  "This beautiful platinum headband is beset with large rubies across the\n"+
  "forehead and has the crest of royalty in its center.\n");
set_ac(2);
set_type("helmet");
set_weight(1);
set_value(1200);
/*
set_save_flag();
*/
}
