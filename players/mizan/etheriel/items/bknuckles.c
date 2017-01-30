inherit "players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("brass knuckles");
    set_long("Ahh... how pleasant! A cheap, effective way of improving the\n"+
	"damage that a set of fists can do.\n");
    set_short("A set of brass knuckles");
    set_class(8);
    set_value(90);
    set_alias("knuckles");
    set_weight(1);
    set_hit_func(this_object());
    
    set_read("The word 'HATE' is stamped into the knuckles.\n");
    set_smell("The knuckles smell like a pair of sweaty Italian fists.\n");
    set_taste("The knuckles really taste like... Calzone?!?\n");
}

weapon_hit(attacker)
{
    if(random(100) < 11) 
    {
        write("You make your opponent's jaw shatter as you connect a brilliant uppercut!\n");
        say((this_player()->query_name())+" lands a punch that goes KLUNG!\n");
        return 2 ;
    }
}




