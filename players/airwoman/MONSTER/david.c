/* Changed unset hp to 500  -Snow */
inherit "obj/monster.talk";
 
reset(arg){
    object money,bone;
    ::reset(arg);
    if(!arg) {
    set_name("david");
    set_alias("thoreau");
    set_level(18);
    set_hp(500);
    set_short("Henry David Thoreau");
    set_long("Thoreau went to the woods to be alone and to enjoy\n"+
    "the simplicities of life...\n");
    set_aggressive(0);
    set_wc(26);
    set_ac(15);
    set_chat_chance(5);
    load_chat("Thoreau says: I came to the woods to suck the "+
        "marrows out of life... \n");
    money=clone_object("obj/money");
    money->set_money(100+random(500));
    move_object(money, this_object());
    bone = clone_object("players/airwoman/food/bone");
    move_object(bone, this_object());
}
}
 
