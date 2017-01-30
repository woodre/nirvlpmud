inherit "players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_name("cheese knife");
    set_class(1);
    set_value(0);
    set_weight(0);
    set_alias("knife");
    set_short("A plastic cheese knife");
    set_long("  This is a plastic cheese knife that can be used to 'cut cheese'.\n"+
             "  Just don't stand too close to other people.\n");
    
    set_read("The plastic cheese knife has no visible writing on it.\n");
    set_smell("The plastic cheese knife smells like... Swiss cheese.\n");
    set_taste("The plastic cheese knife tastes like... SWISS CHEESE!\n");
}

