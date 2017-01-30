inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("isis");
    set_alt_name("rubber woman");
    set_alias("sex toy");
    set_al(0);
    set_level(9);
    set_hp(120);
    set_wc(12);
    set_ac(6);
    set_short(""+MAG+"Isis"+NORM+"");
    set_long(
      "Isis is a rubber woman who belongs to Bud.  Bud uses Isis for,\n"+
      "well . . . you don't want to know what Bud uses her for.\n");
}
