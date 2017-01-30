#include "/obj/ansi.h";
inherit "obj/treasure";

reset(arg)  
{
        if(arg) return;

        set_name("tri_force");
        set_alias("tri");
        set_short(""+HIY+"Triforce"+NORM+"");
        set_long("This tripple triangle is the legendary"+HIY+"Triforce"+NORM+".\n");
        set_weight(1);
        set_value(10);
}