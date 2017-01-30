/* Changed unset hps to 400, aggressive from 0 to 1  -Snow */
inherit "obj/monster.talk";
 
reset(arg){
    object money;
    ::reset(arg);
    if(!arg) {
    set_name("woodsy");
    set_alias("owl");
    set_level(16);
    set_hp(400);
    set_short("Woodsy the Owl");
    set_long("Woodsy the Owl does not like pollution or littering...\n");
    set_aggressive(1);
    set_wc(22);
    set_ac(13);
    set_chat_chance(10);
    load_chat("Woodsy says:  Give a hoot don't pollute!\n");
    money=clone_object("obj/money");
    money->set_money(300+random(500));
    move_object(money, this_object());
}
}
 
