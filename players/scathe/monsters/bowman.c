inherit "obj/monster";

void reset(int arg) {
    object ob;

    ::reset(arg);
    if (arg || root()) return;

    set_name("archer");
    set_race("human");
    set_short("A very strong Archer");
    set_long("\
A muscular archer who bears an extremely large and lethal looking\n\
bow.  His eyes cut you like stone daggers as he calmly draws a bead\n\
on your heart.  Maybe you should leave him alone....\n");
    set_level(20);
    set_hp(500);
    set_al(-1000);
    set_aggressive(1);
    set_chance(33);
    set_spell_dam(10+random(45));
    set_spell_mess2("The Archer blasts you with a force bolt");
    set_spell_mess1("The Archer slams his foe with a force bolt");
    set_chat_chance(20);
    load_chat("The Archer says: Such a slow target.....\n");

    add_money(1500 + random(750));
    ob = clone_object("/players/scathe/weap/lbow");
    move_object(ob, this_object());
    command("wield bow");

   ob = clone_object("/players/scathe/armor/bowarmor.c");
   move_object(ob, this_object());
   command("wear armor");

   ob= clone_object("/players/scathe/armor/bowboot.c");
   move_object(ob, this_object());
   command("wear boots");

    set_wc(30); /* READJUSTED BY WIZARDCHILD */
    set_ac(17); /* READJUSTED BY WIZARDCHILD */
    /*
     * yes, let's have every wc and ac exactly the same..
     * and not think about the 1/3 chance of hit_player [10..54]
     */
}
