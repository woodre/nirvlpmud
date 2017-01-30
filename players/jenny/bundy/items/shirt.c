#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
    if(arg) return;
    set_name("no ma'am shirt");
    set_alias("t-shirt");
    set_id("shirt");
set_ac(2);
set_value(1100);
set_weight(1);
    set_type("armor");
    set_short(""+RED+"A NO MA'AM shirt"+NORM+"");

    set_long(""+RED+
      "This is a white T-shirt with NO MA'AM printed in red letters.\n"+
      "NO MA'AM stands for National Organization of Men Against\n"+
      "Amazonian Masterhood"+NORM+"\n");
}
