inherit "players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_name("broken bowling ball");
    set_alias("ball");

    set_class(5);
    set_value(50);
    set_weight(1);
    set_short("A broken bowling ball");
    set_long("  This is a fourteen pound bowling ball with a huge chip in it. Also, it is\n"+
             "  covered with a series of gashes and dings. It could possibly be used as\n"+
             "  some sort of a weapon...\n");

    set_read("The bowling ball has the words 'Ebonite' written on it.\n");
    set_smell("The bowling ball smells of beer, body odor, and stale hot dogs.\n");
    set_taste("The bowling ball tastes a lot like... oil and blood.\n");
    
}
