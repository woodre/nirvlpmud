#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alt_name("iron bastard sword");
    set_alias("bastard sword");
    set_short("Iron bastard sword");
    set_long("This finely crafted iron sword  forged in the heat of the\n"+
    "dwaven blast furnaces.  Its dull grey sheen absorbs the surrounding\n"+
    "light.\n");
set_class(18);
    set_weight(2);
    set_type("sword");
    set_value(1000);
    set_hit_func(this_object());
}
short() {
   if(environment(this_object()) == "mondar" && wielded) { return "\n"+  "A 1997 "+BOLD+WHT+"Stanley Cup "+NORM+"Championship Ring (worn).\n"+
"A 1998 "+BOLD+WHT+"Stanley Cup "+NORM+"Championship Ring (worn)";
"A 1998 "+BOLD+WHT+"Stanley Cup "+NORM+"Championship Ring (worn)";}
"A 1998 "+BOLD+WHT+"Stanley Cup "+NORM+"Championship Ring (worn)";}


weapon_hit(attacker){
int i;
i = random(3);
if(i==1){
write("Iron bites deep into its foe.\n");
return 6;
}
}
