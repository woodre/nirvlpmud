inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("leonard the grumpy wombat");
    set_race("wombat");
    set_alias("leonard");
    set_short("Leonard the grumpy wombat");
    set_long("Leonard is grumpy. Don't bother him. Don't look at him, it makes\n"+
    "him very nervous. Don't lick him either. It makes him mad.\n");
    set_level(10);
    set_hp(150);
    set_al(0);
    set_ac(8);
    set_wc(14);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Leonard screams: I'm in a BAD mood!");
    set_spell_mess2("Leonard bleats soggily.");
    set_chat_chance(20);
    load_chat("Leonard shows you his teeth.\n");
    load_chat("Leonard goes: Dammit... I'm lost again.\n");
    load_chat("Leonard maws inpatiently.\n");
    load_chat("Leonard complains: There's nothing to graze on here.\n");
    weapon=clone_object("players/mizan/etheriel/items/spuckpistol.c");
    move_object(weapon, this_object());
    move_object(clone_object("players/mizan/etheriel/items/spuckballs-ext"), weapon);
    treasure=clone_object("players/mizan/etheriel/heals/cheese.c");
    move_object(treasure, this_object());
}
