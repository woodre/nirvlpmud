inherit "players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("broken belt sander");
    set_long("Well, just because this is a broken belt sander doesn't mean it is\n"+
             "totally worthless... for example if wielded it makes a perfectly suitable\n"+
             "object to bash the hell out of somebody with.\n");
    set_short("A broken Ryobi belt sander");
    set_class(14);
    set_value(50);
    set_alias("sander");
    set_weight(4);
    set_hit_func(this_object());
    
    set_read("The belt sander is COVERED with Hello Kitty stickers.\n");
    set_smell("The belt sander smells a lot like aluminum. Perhaps that is why it is broken?\n");
    set_taste("The belt sander tastes a lot like aluminum dust. Ick. Ouch. Ick. Ouch.\n");
}

weapon_hit(attacker)
{
    if(random(100) < 15) 
    {
        write("You go wild with the belt sander!\n");
        say((this_player()->query_name())+" swings a broken belt sander wildly! Look out!\n");
        return 2 ;
    }
}




