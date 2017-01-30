#include <ansi.h>
inherit "obj/treasure";

reset(arg)  
{
        if(arg) return;

        set_name("fragment");
        set_alias("tfragment");
        set_short(""+HIK+"fragment"+NORM+"");
        set_long("The top fragment of some kind of mask.\n");
        set_weight(1);
        set_value(10);
}
