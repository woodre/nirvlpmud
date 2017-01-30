#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
    if(arg) return;
    set_name("Sheriff's Hat");
    set_alias("sheriff's hat");
    set_id("hat");
set_ac(1);
set_value(100);
set_weight(1);
    set_type("helmet");
set_short(YEL+"~ "+BLU+"Sheriff's Hat "+YEL+"~"+NORM);

    set_long(
      "This is a black sheriff's hat that belongs to Rosco P. Coltrane.\n"+
      "This hat makes you feel like a real police officer.\n");
}
