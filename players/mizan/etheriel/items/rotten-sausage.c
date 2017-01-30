inherit "players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("rotten sausage");
    set_long("This is a three-foot long sausage that is too rotten for consumption.\n"+
             "However it seems petrified somehow, and is really quite heavy for its\n"+
             "size. Perhaps it would make an effective weapon?\n");
    set_short("A three-foot long, rotten sausage");
    set_class(15);
    set_value(300);
    set_alias("sausage");
    set_weight(3);
    set_hit_func(this_object());
    
    set_read("The sausage has a label on it that reads: 'Path Mark'.\n");
    set_smell("The sausage... smells like... ASS!\n");
    set_taste("The sausage really is inedible. Its surface smells like a moose's colon.\n");
}

weapon_hit(attacker)
{
    if(random(100) < 15) 
    {
        write("You go wild with the rotten sausage! Go get 'em!\n");
        say((this_player()->query_name())+" swings a three-foot long, rotten sausage! OH THE HORROR!\n");
        return 2 ;
    }
}




