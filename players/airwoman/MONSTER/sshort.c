/* Changed lev.18 to 15, unset hp to 320  -Snow */
inherit "obj/monster.talk";
 
reset(arg){
    object money,berry;
    ::reset(arg);
    if(!arg) {
    set_name("strawberry shortcake");
    set_alias("shortcake");
    set_level(15);
    set_hp(320);
    set_short("Strawberry Shortcake");
    set_long("Remember Strawberry Shortcake? She likes to\n"+
             "tend her strawberry fields...\n");
    set_aggressive(0);
    set_wc(15);
    set_ac(26);
    set_chat_chance(10);
    load_chat("Strawberry Shortcake says:  smell my hair...\n");
    money=clone_object("obj/money");
    money->set_money(500+random(500));
    move_object(money, this_object());
    berry=clone_object("players/airwoman/food/berry");
    move_object(berry, this_object());
}
}
 
init() {
  add_action("smell_hair", "smell");
   ::init();
}
 
smell_hair(str)
{
   if(str == "hair")
   {
        write("You smell Strawberries shortcake's hair....\n");
        write("It smells like fresh Strawberries forever...\n");
        say(this_player()->query_name()+ " smells"+
        " Strawberry Shortcake's hair...\n");
 	return 1;
    }
}
