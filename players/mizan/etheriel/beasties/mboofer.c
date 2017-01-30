inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/Tracking-D.c"

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("Boofer");
    set_race("boofer");
    set_alias("boofer");
    set_short("Slightly Mutated Boofer");
    set_long("You have seen a Boofer before, right? This one make all sorts of\n"+
    "funny noises too, except it is a lot bigger, and it makes them alot louder.\n");
    set_level(18);
    set_hp(480);
    set_al(100);
    set_wc(24);
    set_ac(16);
    set_chance(20);
    set_spell_dam(20);
    set_spell_mess1("Boofer boggles biggly at you");
    set_spell_mess2("Boofer flugs loudly and hits you with its wub!");
    set_chat_chance(20);
    load_chat("Boofer goes: 'Yoomle.\n");
    load_chat("Boofer goes: 'gwak'\n");
    load_chat("Boofer bloats up for a moment, then shrinks again.\n");
    load_chat("Boofer folds in half and disappears.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(500)+150);
    move_object(gold,this_object());
    weapon=clone_object("players/mizan/etheriel/items/purple-stick.c");
    move_object(weapon, this_object());
    armor=clone_object("players/mizan/etheriel/items/spuckhelm.c");
    move_object(armor, this_object());
    armor=clone_object("players/mizan/etheriel/items/spucksuit.c");
    move_object(armor, this_object());
}
