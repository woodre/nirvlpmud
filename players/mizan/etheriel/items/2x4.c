inherit "players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_name("two by four");
    set_alias("plank");

    set_class(15);
    set_value(90);
    set_weight(1);
    set_short("A two-by-four plank");
    set_long("  This is a plank of two-by-four wood. It has been sawed off and sanded to\n"+
             "  a nice, comfortable 'riot length'. You could possibly use it as a weapon.\n");
    
    set_read("The word 'Weyerhauser' is barely legible on the two-by-four.\n");
    set_smell("The plank smells quite like white pine. Or perhaps poplar?\n");
    set_taste("The WOOD plank tastes surprisingly like WOOD.\n");

}
