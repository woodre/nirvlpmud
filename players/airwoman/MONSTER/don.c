inherit "obj/monster.talk";
 
reset(arg){
    object money,pizza;
    ::reset(arg);
    if(!arg) {
    set_name("donatello");
    set_alias("don");
    set_level(6);
    set_hp(100);           
    set_short("Donatello -- Teenage Mutant Ninja Turtle");
    set_long("Don is a mutant. Just kill him.  Im sick of these "+
    "turtles...\n");
    set_aggressive(0);
    set_wc(5);
    set_ac(3);
    set_chat_chance(20);
    load_chat("Donatello says: I love the smell of sewers! \n");
    money=clone_object("obj/money");
    money->set_money(100+random(500));
    move_object(money, this_object());
    pizza = clone_object("players/airwoman/food/pizza");
    move_object(pizza, this_object());
}
}
 
