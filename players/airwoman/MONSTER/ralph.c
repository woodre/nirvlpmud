inherit "obj/monster.talk";
 
reset(arg){
    object money,pizza;
    ::reset(arg);
    if(!arg) {
    set_name("raphael");
    set_alias("ralph");
    set_level(6);
    set_hp(100);           
    set_short("Raphael -- Teenage Mutant Ninja Turtle");
    set_long("Ralph is a mutant. He sux.  Kill him...\n");
    set_aggressive(0);
    set_wc(10);
    set_ac(5);
    set_chat_chance(20);
    load_chat("Raphael says: huh? \n");
    money=clone_object("obj/money");
    money->set_money(100+random(50));
    move_object(money, this_object());
    pizza = clone_object("players/airwoman/food/pizza");
    move_object(pizza, this_object());
}
}
 
