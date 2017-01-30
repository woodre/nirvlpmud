
inherit"obj/monster";
#include "/players/catt/AREAS/base_defines.c"

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) return;
    set_name("zombie");
    set_alias("zombie");
    set_short("ugly zombie");
    set_long("This is an ugly zombie. He doesn't seem to like you much.\n");
    set_level(2);
    set_aggressive(0);
    set_race("zombie");
    set_chat_chance(10);
    load_chat("Zombie says: DIE MORTAL AND BECOME LIKE US!\n");
    load_chat("Zombie gasps: DESTROY ALL MORTALS!\n");
    set_hp(30+random(20));
    set_al(-200);
    set_wc(6);
    set_ac(3);
    set_can_kill(100);
    set_random_pick(0);
    money = clone_object("obj/money");
    money->set_money(random(40) + 40);
    move_object(money, this_object());
}
