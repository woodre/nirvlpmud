inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/RandomMove.c"

reset(arg)
{
    object gold;
    object thingo;
    ::reset(arg);
    if(arg) return;
    set_name("barney");
    set_name("barney");
    set_alias("barney");
    set_short("Barney the psychotic purple dinosaur");
    set_level(15);
    set_hp(235);
    set_al(-540);
    set_wc(24);
    set_ac(15);
    set_chance(20);
    set_spell_dam(25);
    set_spell_mess1("Barney cackles: Die! Die! Die!\n");
    set_chat_chance(20);
    load_chat("Barney goes: I HATE kids, they HATE me...\n");
    load_chat("Barney says: Godzilla's a WUSS!\n");
    load_chat("Barney goes: The true God is SATAN!\n");
    load_chat("Barney cackles manically.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
    thingo=clone_object("players/mizan/etheriel/items/spuck-shotgun.c");
    move_object(clone_object("players/mizan/etheriel/items/spuckballs-ext.c"), thingo);
    move_object(thingo, this_object());
    move_object(clone_object("players/mizan/etheriel/items/spuckballs.c"), this_object());
}
