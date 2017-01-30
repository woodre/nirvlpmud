inherit "/players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("wooden sword");
    set_long("Honestly, this is a stupid looking weapon.\n"+
	"But hey! It works, and pretty damn well for a wooden sword\n"+
	"so stop making fun of it!\n");
    set_short("A wooden sword");
    set_class(10);
    set_value(350);
    set_alias("sword");
    set_weight(1);

    set_hit_func(this_object());

    set_read("The wooden sword has the words 'FAT AND SASSY' written on it.\n");
    set_taste("The wooden sword tastes a lot like... dirt.\n");
    set_smell("The wooden sword smells like fungus.\n");

}

weapon_hit(attacker) 
{
    if(random(100) < 11) 
    {
        write("This thing is actually rather fun to beat people on the head with!\n");
        say((this_player()->query_name())+" makes you cringe in terror (It's that wooden sword).\n");
        return 2 ;
    }
}
