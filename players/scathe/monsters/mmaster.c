inherit "obj/monster";

void reset(int arg) {
    object ob;

    ::reset(arg);
    if (arg || root()) return;
    set_name("Monk of the Dragon Fist Order");
    set_alias("master");
    set_alt_name("monk");
    set_race("human");
    set_short("Master Monk of the Dragon Fist Order");
    set_long("\
A Master of the Order, this man has overcome many challenges to\n\
attain his status.  He is a strong, tough looking individual who\n\
looks capable of beating you senseless.  Are you sure that you want\n\
to challenge him?\n");
    set_level(20);
    set_hp(500);
    set_al(-1000);
    set_chance(55);
    set_spell_dam(20 + random(40));
    set_spell_mess2("The monk concentrates for a moment, and strikes you with a glowing fist.");
    set_spell_mess1("The monk smashes his foe with a glowing fist!");
    set_chat_chance(20);
    load_chat("The Master asks: What are you doing here? Get back to the yards!!\n");
    add_money(20 + random(750));
/* Changed from random(3) to random(2)  -Snow */
   if(random(2) == 0) set_aggressive(1);

    if (root()) return;
    ob = clone_object("/players/scathe/armor/damulet");
    move_object(ob, this_object());
    command("wear amulet");

    ob = clone_object("/players/scathe/armor/garb");
    move_object(ob, this_object());
    command("wear garb");
     set_wc(30);
    set_ac(17);
}
