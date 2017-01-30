inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("mokbeast");
    set_race("mokbeast");
    set_short("A hairy mokbeast");
    set_long("This thing looks like its made of pure.... armpit hair. Ick.\n");
    set_level(7);
    set_hp(105);
    set_al(-600);
    set_ac(6);
    set_wc(11);
}
