inherit "obj/monster.talk";
 
reset(arg){
   object pizza;
    ::reset(arg);
    if(!arg) {
    set_name("michaelangelo");
    set_alias("mike");
    set_level(6);
    set_short("Michaelangelo -- Teenage Mutant Ninja Turtle");
    set_long("Mike is a mutant. Just kill him.  Im sick of these "+
    "turtles...\n");
    set_aggressive(0);
    set_wc(10);
    set_ac(5);
    set_chat_chance(20);
    load_chat("Michaelangelo says: Pizza? \n");
    pizza = clone_object("players/airwoman/food/pizza");
    move_object(pizza, this_object());
}
}
 
