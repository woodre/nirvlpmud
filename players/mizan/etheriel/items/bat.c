inherit "players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_name("bat");
    set_class(12);
    set_value(350);
    set_weight(2);
    set_alias("bat");
    set_short("A bloodstained baseball bat");
    set_long("  This is an aluminum baseball bat caked with blood. Interesting.\n");
    set_hit_func(this_object());
    
    set_read("The bat has no writing left on it, but you could swear it said 'Easton' as the brand.\n");
    set_smell("The bat smells really, really fishy.\n");
    set_taste("The bat tastes like cold blood. YAY!\n");
}

weapon_hit(attacker)
{
    if(random(10) < 2) return 4;
}

query_save_flag() { return 1; }
