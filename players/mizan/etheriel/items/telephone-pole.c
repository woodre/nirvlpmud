/*

 THIS WEAPON HAS WC 23.

It also weighs 12. _12_. Twelve. Doce. 12 == heavy.
HEAVY.
H E A V Y.

*/

inherit "/players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("telephone pole");
    set_short("A telephone pole");
    set_class(23);
    set_value(3000);
    set_alias("pole");
    set_weight(12);
    set_hit_func(this_object());
    set_long("This is a very BIG stick, about the size of a tree.\n"); 

    set_read("The telephone pole has the word 'Weyerhauser' written on it.\n");
    set_smell("The telephone pole smells like a GODDAMN TREE!\n");
    set_taste("You lick the telephone pole. Yourth mouth ith fullth oth splinthers\n");

    set_limited_issue(1);
    set_limited_issue_count(2);

}

weapon_hit(attacker)
{
    if(random(100) < 11) 
    {
        write("You smash your opponent with a telephone pole!\n");
        say((this_player()->query_name())+" goes batty with a telephone pole!\n");
        return 2 ;
    }
}
