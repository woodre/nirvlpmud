inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg) return;

    set_name("morph");
    set_alias("dopple");
    set_race("morph");
    set_short("A Dopple Morph");
    set_long("\
Someone must have been bothering this Dopp, for it retreated into\n\
its ugly little Morph form.  Feel free to finish it off.\n");
    set_level(6 + random(3));
    set_hp(80 + random(40));
    set_al(-300);
    set_wc(8 + random(5));
    set_ac(4 + random(4));
    set_chance(9);
    set_spell_dam(3 + random(3));
    set_spell_mess1("Morph swirls about in an attempt to recruit you!!!");
    set_spell_mess2("Morph crawls over its foe!");
    set_chat_chance(20);
    load_chats(({
        "Morph snivels: Go away!!! Leave us Dopps in peace!!!!\n",
        "Morph can't figure out how to mail the Grime Reaper without changing.\n"
        }));
    add_money(260 + random(80));
}
