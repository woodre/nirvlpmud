/* Patchwork Cloak */

inherit "obj/armor";
inherit "obj/container.c";
#include "/players/jareel/define.h"

  reset(arg) {
    ::reset(arg); 
    if (arg) return;
    set_name("cloak");
    set_short(HIK+"Demon Cloak "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
    set_long(
      "Demon Cloaks are forged in the sun fires of Yelm. An ancient\n"+
      "practice that turns chaotic flesh into a protective shell.\n"+
      "You can store items in the cloaks dark void.\n"+
      "");
    set_light(1);
    set_ac(1);
    set_type("cloak");
set_weight(1);
x

    set_value(5000);
    set_max_weight(30);/*I changed the # to be in line with mud standards ANGEL*/
}
