inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("scathey");
    set_race("scathe");
    set_short("Scathey, one of many Scathes");
    set_long("\
This is one of many Scathes.  Feel free to kill it, there always seem\n\
to be more of them wandering around.  You wonder where their little\n\
pets have run off to.....\n");
    set_level(5 + random(3));
    set_hp(60 + random(50));
    set_al(-200);
    set_wc(7 + random(5));
    set_ac(3 + random(4));
    set_chance(7);
    set_spell_dam(2 + random(3));
    set_spell_mess1("The scathe mails the Boltar about you!!!");
    set_spell_mess2("The wussy Scathe heads for the post office.");
    set_chat_chance(20);
    load_chats(({
        "Scathe whines: I am a complete tool?!?!?! WAH!!!\n",
        "Scathe whimpers: I just want mud screw!!!!\n",
        }));
    add_money(225 + random(60));
}
