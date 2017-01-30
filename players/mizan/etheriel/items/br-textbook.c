inherit "/players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("textbook");
    set_long("This is a peculiar looking textbook, covered with a knuckle-hard\n"+
          	 "skin of some sort, that apparently can cause damage... \n");
    set_short("A textbook");
    set_class(9);
    set_value(500);
    set_alias("book");
    set_weight(2);
    set_hit_func(this_object());

    set_read("The book is titled 'Meat Hygiene. A Primer to Meat and Meat-Based Food Preparation.\n");
    set_smell("The book smells like rotten meat.\n");
    set_taste("The book tastes like... sausages!\n");

}

weapon_hit(attacker) 
{
    if(random(100) < 15) 
    {
        write("You smash your opponent squarely where it counts... with a book!\n");
        say((this_player()->query_name())+" looks really impressive wielding a book.\n");
        return 1;
    }
}
