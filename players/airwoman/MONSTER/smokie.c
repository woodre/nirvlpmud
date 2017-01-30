/* Changed level from 18 to 15, hp 260 to 300  -Snow */
inherit "obj/monster.talk";
 
reset(arg){
    object money;
    ::reset(arg);
    if(!arg) {
    set_name("smokie");
    set_alias("smokie");
     set_level(15);
    set_short("Smokie the Bear");
    set_long("Smokie wants you to be careful when camping.\n"+
             "Do not endanger your life and the environment.\n");
    set_aggressive(0);
  set_hp(300 + random(90));
    set_wc(22);
    set_ac(15);
    set_chat_chance(10);
    load_chat("Smokie says: I hate forest fires!\n");
    money=clone_object("obj/money");
    money->set_money(450+random(500));
    move_object(money, this_object());
}
}
 
