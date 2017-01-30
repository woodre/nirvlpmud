#include <ansi.h>
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Bone Staff");
set_type("staff");
set_alias("quarterstaff");
set_short(WHT+"Bone laced"+NORM+" Quarterstaff"+NORM);
set_long("A strong wooden quarterstaff makes an excellent weapon, and this one\n"+
         "has been reinforced with interlocking bones laced along its\n"+
         "length.\n");
set_class(20);
set_weight(1);
set_value(2500+random(1000));
}
