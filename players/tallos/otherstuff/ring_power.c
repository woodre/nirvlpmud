#include <ansi.h>
inherit "obj/armor.c";
reset(arg){
object ring;
set_name("ring");
set_ac(2);
set_weight(1);
set_type("ring");
set_arm_light(1);
set_short("A "+CYN+"ring of power"+NORM);
set_long("A Beautiful Glowing Ring...\n");
set_value(1200);
}
