inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure,treasure2;
    ::reset(arg);
    if(arg) return;
    set_name("mamie the jackrabbit");
    set_race("jackrabbit");
    set_alias("mamie");
    set_short("Mamie the lonesome jackrabbit");
    set_long(".\n");
    set_level(12);
    set_hp(180);
    set_al(0);
    set_ac(8);
    set_wc(16);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Mamie screams and kicks you in the... in the... well.. it hurt.");
    set_spell_mess2("Mamie smacks you!");
    set_chat_chance(20);
    load_chat("Mamie goes: I can't believe he did that...\n");
    load_chat("Mamie sighs: Men... who needs them?\n");
    load_chat("Mamie says: Ahh... Life goes on.\n");
    load_chat("Mamie smiles happily.\n");
    weapon=clone_object("players/mizan/etheriel/heals/soybean.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/poohbear.c");
    move_object(treasure, this_object());
    treasure2=clone_object("players/mizan/etheriel/items/rose.c");
    move_object(treasure2, this_object());
}
