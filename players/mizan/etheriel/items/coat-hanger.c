inherit "players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_name("coat hanger");
    set_alias("hanger");

    set_class(6);
    set_value(50);
    set_weight(1);
    set_short("A coat hanger");
    set_long("  This is an ordinary coat hanger bent into a scary-looking hook.\n"+
             "  It could possibly be used as a weapon, but not a very effective one.\n");
    
    set_read("A small tag hangs off the hanger, and it reads 'Bill French Cleaners'.\n");
    set_smell("The coat hanger smells of cheap perfume.\n");
    set_taste("The coat hanger tastes a lot like cheap metal and cardboard.\n");
}
