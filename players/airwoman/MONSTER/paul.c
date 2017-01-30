/* Changed from lev.24 to 22, hp500 to 1000, moved wc/ac settings below
   wield command (to avoid being reset by wield) -Snow */
inherit "obj/monster.talk";
 
reset(arg){
    object money,ax;
    ::reset(arg);
    if(!arg) {
    set_name("paul bunyan");
    set_alias("paul");
    set_level(22);
    set_hp(1000);
    set_short("Paul Bunyan");
    set_long("Paul Bunyan...the lumber jack guy remember?\n");
    set_aggressive(0);
    set_chat_chance(10);
    load_chat("Paul Bunyan says: Dont mess with me or you'll die!\n");
    set_a_chat_chance(10);
    load_a_chat("Paul Bunyan raises his ax and smashes it hard on"+
        " your head\n");
    money=clone_object("obj/money");
    money->set_money(1000+random(500));
    move_object(money, this_object());                       
    ax= clone_object("players/airwoman/WEAPONS/ax");
    move_object(ax, this_object());
    command("wield ax", this_object());   
    set_wc(36);
    set_ac(20);
}
}
 
