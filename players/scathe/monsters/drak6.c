inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("drak");
    set_race("dragon");
    set_short("A large Drak");
    set_long("\
As large as most adult dragons, it is a very formidable foe to\n\
defeat. You cant help but be impressed by its incredible speed,\n\
its claws moving in a flash....\n");
    set_aggressive(1);
    set_level(20);
    set_hp(500);
    set_al(-1000);
    set_wc(30);
    set_ac(17);
    set_chance(33);
    set_spell_dam(30+random(15));
    set_spell_mess1("The drak's teeth rip your flesh.");
    set_spell_mess2("The drak's teeth rip the flesh of its foe.");
    set_chat_chance(20);
    load_chat("The drak hisses and spits at you.\n");
    add_money(random(100)+600);
}
