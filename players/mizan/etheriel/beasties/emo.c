inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("emo");
    set_race("emo");
    set_alias("dummy");
    set_short("Emo the incredibly odd");
    set_long("Emo is of all things, a hedgehog. Actually, he's a tad\n"+
    "bit senile, but generally harmless.\n"); 
    set_level(7);
    set_hp(100);
    set_al(130);
    set_ac(6);
    set_wc(11);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Emo screams and tucks into a ball.");
    set_spell_mess2("Emo goes: Wiiiiiiilllllbuurrrrrr!");
    set_chat_chance(20);
    load_chat("Emo says: Want to buy sum ting?\n");
    load_chat("Emo says: Orange good for you.\n");
    load_chat("Emo says: I am fine, thank you!\n");
    weapon=clone_object("players/mizan/etheriel/heals/bunupill.c");
    move_object(weapon, this_object());
    treasure=clone_object("obj/money.c");
    treasure->set_money(1);
    move_object(treasure, this_object());
}
