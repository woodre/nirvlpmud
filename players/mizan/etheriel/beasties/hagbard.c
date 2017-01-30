inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold,armor,weapon,booze;
    ::reset(arg);
    if(arg) return;
    set_name("hagbard");
    set_race("human");
    set_alias("hagbard");
    set_short("Old Hagbard the geezer (retired)");
    set_long("His face worn but not scarred, his beard thick but not long,\n"+
    "and his brain bungled but not fried, Old Hagbard spends his time\n"+
    "drifting about in the ether-muck reminiscing about the good-old-days\n"+
    "speaking to no one in paticular\n");
    set_level(15);
    set_hp(225);
    set_al(100);
    set_wc(20);
    set_ac(12);
    set_chance(20);
    set_spell_dam(15);
    set_spell_mess1("Hagbard cries: The king is dead! Long live the king!");
    set_spell_mess2("Hagbard grins biggly and cries: Ahh, the taste of battle!");
    set_chat_chance(10);
    load_chat("Hagbard makes hand gestures and rambles: I killed a dragon THIS big...\n");
    load_chat("Hagbard says: Those were the good old days...\n");
    load_chat("Hagbard rambles: The Barbarian guild was the best... Yups.\n");
    load_chat("Hagbard cries: I killed a whole room of Kobolds in ten rounds once!\n");
    load_chat("Hagbard burps rudely.\n");
    load_chat("Hagbard hiccups.\n");
    load_chat("Hagbard appears drunk.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(10)+15);
    move_object(gold,this_object());
    armor=clone_object("players/mizan/etheriel/items/crappy-armor.c");
    move_object(armor, this_object());
    weapon=clone_object("players/mizan/etheriel/items/rusty-sword.c");
    move_object(weapon, this_object());
    booze=clone_object("players/mizan/etheriel/heals/cheap-liquor.c");
    move_object(booze, this_object());
}
