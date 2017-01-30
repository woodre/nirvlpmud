inherit "obj/monster";

void reset(int arg) {
    object ob;
    ::reset(arg);
    if (arg || root()) return;

    set_name("Monk of the Dragon Fist Order");
    set_alias("elder");
    set_alt_name("monk");
    set_race("human");
    set_short("An Elder of the Dragon Fist Order");
    set_long("\
An older man, the Elder has mastered the mind and its relation to\n\
the body and its surroundings.  A great deal of his strength is not\n\
physical, but mental.  He smiles with an air of great confidence,\n\
as he does not know the meaning of the word 'defeat'.\n");
    set_aggressive(1);
    set_level(20);
/* Changed from 500 to 600 (still tough as nails)  -Snow */
    set_hp(600);
    set_al(-1000);
    set_chance(60);
/* Changed from random(10) to random(15)  (skill hits)  -Snow */
    set_spell_dam(20+random(15));
    set_spell_mess2("The monk concentrates for a moment, and strikes you with a glowing fist.");
    set_spell_mess1("The monk smashes his foe with a glowing fist!");
    set_chat_chance(20);
    load_chat("The Elder says: The Grandmaster does not wish to be disturbed!!\n");
    add_money(3500 + random(750));

    ob = clone_object("/players/scathe/armor/damulet");
    move_object(ob, this_object());
    command("wear amulet", this_object());

    ob = clone_object("/players/scathe/armor/egarb");
    move_object(ob, this_object());
    command("wear garb", this_object());
/* Changed from 30 to 25  (older)  -Snow */
    set_wc(25);
    set_ac(17);
}

#include "/players/mythos/amon/hb_ag.h"
