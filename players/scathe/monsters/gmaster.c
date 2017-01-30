inherit "obj/monster";
#include "/players/beck/MortalKombat/MKQuestNPC.h"

void reset(int arg) {
    object ob;
    ::reset(arg);
    if (arg || root()) return;

    set_name("Grandmaster");
    set_alias("grandmaster");
    set_alt_name("monk");
    set_race("human");
    set_short("Grandmaster of the Dragon Fist Order");
    set_long("\
An elderly man with a bald head and long flowing snow white beard,\n\
dressed in a long black monk's robe.  He is carrying a large walking\n\
stick with strange markings on it.  Don't be fooled by his age, for\n\
his wisdom has allowed him to transcend many mortal constraints.\n");
    set_aggressive(1);
    set_level(23);
    set_hp(650);
    set_al(-1000);
    set_chance(80);
    set_spell_dam(35+random(10));
    set_spell_mess2("The monk concentrates for a moment, and strikes you with a glowing fist.");
    set_spell_mess1("The monk smashes his foe with a glowing fist!");
    set_chat_chance(20);
    load_chat("The Grandmaster says: Are you here to train?\n");
    add_money(random(2750)+50);

    ob = clone_object("/players/scathe/armor/damulet");
    move_object(ob, this_object());
    command("wear amulet", this_object());

    ob = clone_object("/players/scathe/armor/mgarb");
    move_object(ob, this_object());
    command("wear garb", this_object());

/*
    move_object(clone_object("players/scathe/closed/rod1"), this_object());
*/
    set_wc(36);
    set_ac(20);
  move_object(clone_object("/players/dragnar/MKScar/scar"), this_object());
}
