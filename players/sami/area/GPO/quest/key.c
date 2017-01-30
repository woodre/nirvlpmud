#include <ansi.h>
inherit "obj/treasure";

reset(arg)  
{
        if(arg) return;

        set_name("key");
        set_alias("samikey");
        set_short(HIK+"Key"+NORM);
        set_long("This key is rusted and jagged. Blood stains its surface.\n");
        set_weight(1);
        set_value(10);
}
