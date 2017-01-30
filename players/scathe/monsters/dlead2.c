inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("Dopple Leader");
    set_alias("dopp");
    set_alt_name("leader");
    set_race("doppleganger");
    set_short("A Dopple Leader");
    set_long("\
This is a Dopple Guild Leader.  He seems to have more backbone than\n\
other Dopps, but appearences in this case are VERY deceiving.  He\n\
looks ready to run away.....\n");
    set_level(8 + random(4));
    set_hp(130 + random(40));
    set_al(-400);
    set_wc(11 + random(6));
    set_ac(6 + random(4));
    set_chance(10);
    set_spell_dam(5 + random(5));
    set_spell_mess1("Dopp Leader summons a wussy Dopp horde on you!");
    set_spell_mess2("Dopp Leader slams a whining Dopp on its foe!");
    set_chat_chance(20);
    load_chats(({
        "Dopple Leader threatens: Mess with me, you mess with the Wussy Dopples!\n",
        "Dopple Leader says: The Grime Reaper will get you!!!!\n",
        }));
    add_money(400 + random(110));
}
