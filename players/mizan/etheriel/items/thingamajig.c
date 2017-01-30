inherit "/players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("thingamajig");
    set_class(8);
    set_value(80);
    set_weight(1);
    set_alias("thingamajig");
    set_short("A thingamajig");
    set_long(
        "This is a thingamajig. After some time, you decide that it can be 'wielded'.\n"+
        " \(This is the newbie version.\)\n");

    set_hit_func(this_object());

    set_read("The thingamajig has no discernable writing on it.\n");
    set_smell("The thingamajig smells like... dried oranges.\n");
    set_taste("The thingamajig tastes like oranges!\n");

}

weapon_hit(attacker)
{
    if(this_player())
        write(" You have ["+(this_player()->query_hp())+"] hp.\n");
    
    if(random(10) < 3) return 1;
}

