inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("drak");
    set_race("dragon");
    set_short("Guardian Drak");
    set_long("\
The Guardian Drak was selected to protect the Lord due to his\n\
tremendous strength and magical ability.  It moves forward to\n\
rid the Lord of your bothersome presence.\n");
    set_aggressive(1);
/* Changed from 20 to 21  -Snow */
    set_level(21);
/* Changed from 500 to 600 -Snow */
    set_hp(600);
    set_al(-1000);
    set_wc(30);
    set_ac(17);
    set_chance(65);
    set_spell_dam(35+random(20));
    set_spell_mess1("The drak's teeth rip your flesh.");
    set_spell_mess2("The drak's teeth rip the flesh of its foe.");
    set_chat_chance(20);
    load_chat("The drak hisses and spits at you.\n");
    add_money(10 + random(100));
}
