inherit "obj/monster.talk";
 
reset(arg){
    object money,cabbage;
    ::reset(arg);
    if(!arg) {
    set_name("cabbage patch kid");
    set_alias("kid");
    set_level(6);
    set_short("Cabbage Patch Kid");
    set_long("In 1984, Cabbage Patch Kids were the most "+
	"popular dolls...\n"); 
    set_aggressive(0);
    set_wc(10);
    set_ac(5);
       set_chat_chance(5);
    load_chat("Cabbage Patch Kid says: Can you believe that "+
                "crazy people actually spent over $100 for one of "
	+"us!@ \n"); 
    load_chat("Cabbage Patch Kid says: Well we grow here...in our "+
               "cabbage farm?\n");
    load_chat("Cabbage Patch Kid says: If you think I'm cute, you "+
        "are definitely a nut head!\n");
    cabbage=clone_object("players/airwoman/food/cabbage");
    move_object(cabbage, this_object());
}
}
 
