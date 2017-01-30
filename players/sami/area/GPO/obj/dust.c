#include <ansi.h>
inherit "obj/treasure";

reset(arg)  
{
        if(arg) return;

        set_name("vampire dust");
        set_alias("dust");
        set_short(""+HIG+"V"+HIK+"ampire "+HIG+"D"+HIK+"ust"+NORM+"	");
        set_long("A pile of ashes that used to be a Vampire, who would have thought?\n");
        set_weight();
        set_value(10);
}
