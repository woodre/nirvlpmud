inherit"obj/monster";

#include "/players/catt/AREAS/base_defines.c"

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) return;
    set_name("lag demon");
    set_alias("demon");
    set_short("lag demon");
    set_long("A lag demon that craves slowing down the mud and cause mud crashes!!!!\n");
    set_level(1);
    set_race("demon");
    set_hp(150);
    set_al(-400); /* Alignment from -70000 to -400 Vital 21/9/2003 */
    set_wc(4); /* Changed to reflect monster.guide Vital 21/9/2003 -1ac for greater hps*/
    set_ac(2); /* Changed to reflect monster.guide Vital 21/9/2003 -1wc for spell damage*/
    set_chance(50);
    set_spell_dam(5);
    set_spell_mess1("LAG IS INCREASED ALL OVER THE MUD! HAHAHAHAHAHA");
    set_spell_mess2("LAG IS INCREASED CAUSING MUD WIDE DISRUPTION!!");
    weapon = clone_object(MAGICAL+"lagwand");
    if(weapon) {
        move_object(weapon,this_object());
        command("wield "+weapon->query_name());
    }
}
