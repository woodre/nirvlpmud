#include <ansi.h>
inherit "obj/treasure";

reset(arg)  
{
        if(arg) return;

        set_name("mask");
        set_alias("smask");
        set_short("Mask of the "+HIK+"Undead"+NORM+"");
        set_long("The only thing that remains from the dark ruler Vlad the impaler.\n");
        set_weight(1);
        set_value(10);
}
