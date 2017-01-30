inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("Grime Reaper");
    set_alias("grime");
    set_alt_name("reaper");
    set_race("human");
    set_short("The Grime Reaper");
    set_long("\
The Grime Reaper is covered in hordes of whining Dopples.  Have no\n\
fear of him, all he will do is what Dopps do best:  Mail a god to\n\
whine about the mud.\n");
    set_level(20);
    set_hp(500);
    set_al(-1000);
    set_wc(30);
    set_ac(17);
    set_chance(20);
    set_spell_dam(40);
    set_spell_mess1("The Grime Reaper copies your attack!!!!");
    set_spell_mess2("The Grime Reaper cheats some more to beat you up!!!!");
    set_chat_chance(20);
    load_chats(({
"Grime Reaper cries: The Alchemists are so powerful! I Must Cheat More!\n",
"Grime Reaper pleads: We are just wussy Dopples, please don't hurt us or our pets.\n",
        }));
    add_money(900 + random(100));
}
