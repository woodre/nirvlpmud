#include "/players/fred/ansi.h"
inherit "/obj/armor";

  reset(arg){
    if(arg) return;
    set_name("orange hood");
    set_alias("hood");
    set_short("An "+HIR+"Orange"+NORM+" Hood");
    set_long(
     "  This is the orange hood that Kenny is famous for.\n"+
     "You are tempted to wear it.\n");
    set_ac(1);
    set_type("helmet");
    set_weight(1);
    set_value(200); }
