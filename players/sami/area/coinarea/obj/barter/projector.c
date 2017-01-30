#include <ansi.h>
inherit "obj/treasure";

reset(arg)  
{
        if(arg) return;

        set_name("broke_projector");
        set_alias("projector");
        set_short("A "+HIR+"broken"+NORM+" projector"+NORM+"");
        set_long("This projector is broke but you may be able to "+HIY+" exchange"+NORM+" it for "+HIY+"cash"+NORM+".\n");
        set_weight(1);
        set_value(10);
}
