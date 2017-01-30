inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/HighLevelGuard.c"

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("spuckball");
    set_race("spuckball");
    set_alias("ball");
    set_short("A silent Spuckball");
    set_long("This is a small, spongy ball that constantly changes colors\n"+
    "as it darts around the area. It's really beginning to get annoying!\n");
    set_level(2);
    set_hp(25);
    set_al(0);
    set_ac(3);
    set_wc(5);
    treasure=clone_object("obj/money");
    treasure->set_money(20+random(10));
    move_object(treasure, this_object());
}
