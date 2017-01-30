#include <ansi.h>
inherit "obj/armor";
reset(arg){
   ::reset(arg);

set_name("lavender robes");
set_short(HIM+"Lavender Monk's Robes"+NORM);
set_alias("robes");
set_long("Lavender monk's robes, offering both excellent protection and\n"+
            "extremly flexibility during a fight.\n");
set_type("armor");
set_ac(4);
set_weight(1);
set_value(1175);
}
