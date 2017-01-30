inherit "obj/monster";

void reset(int arg) {
    object ob;

    ::reset(arg);
    if (arg || root()) return;

    set_name("warrior");
    set_race("human");
    set_short("A wandering warrior");
    set_long("A wandering warrior who challenges you to combat.\n\
Beware his blade, it is swift and deadly.\n");
    set_level(19);
    set_hp(475);
    set_aggressive(1);
    set_al(-1000);
    set_chance(33);
    set_spell_dam(30+random(15));
    set_spell_mess2("You wince in pain as the Warrior's blade cuts deep.");
    set_spell_mess1("The warrior's blade blurs as he strikes deep into his foe.");
    set_chat_chance(20);
    load_chats(({
        "The warrior sneers:  Challenge me, and feel the bite of my blade!!!\n",
        "The warrior boasts: Think you can best me??? Try it!!!\n",
        }));

    ob = clone_object("/players/scathe/weap/blade");
    move_object(ob, this_object());
   command("wield blade");

   ob = clone_object("/players/scathe/armor/warmor.c");
   move_object(ob, this_object());
   command("wear plate", this_object());
    set_wc(22);
    set_ac(16);
}
